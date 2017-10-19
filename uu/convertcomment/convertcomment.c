
#include"convertcomment.h"
typedef enum
{
	no_comment_state,
	c_comment_state,
	cpp_comment_state,
	string_comment_state,
	end_state
}enum_state;
typedef struct
{
	FILE *input;
	FILE *output;
	enum_state ulstate;
}state_machine;
//定义状态机
state_machine g_state;
static enum_state g_pre_state;
//////////////////
int convertcomment(FILE *inputfile,FILE *outputfile)
{
	if(NULL == inputfile ||NULL == outputfile)
	{
		printf("invalid argument inputfile or outputfile ");
		return -1;
	}
	g_state.input = inputfile;
	g_state.output = outputfile;
	g_state.ulstate = no_comment_state;
	char ch;
	while(g_state.ulstate!=end_state)
		{
			ch=fgetc(g_state.input);
			eventpro(ch);
		}

return 0;
}

void eventpro( char ch)
{
switch(g_state.ulstate)
  {
	case no_comment_state:
	eventpro_no(ch);
	break;
	case c_comment_state:
	eventpro_c(ch);
	break;
	case cpp_comment_state:
	eventpro_cpp(ch);
	break;
	case string_comment_state:
	eventpro_str(ch);
	break;
  }
}
void eventpro_no(char ch)
{
	char nextch;
	switch(ch)
{
		case '/':
		nextch=fgetc(g_state.input);
		if(nextch == '/')
		{
			fputc('/',g_state.output);
			fputc('*',g_state.output);
			g_state.ulstate = cpp_comment_state;
		}
		else if(nextch=='*')
		{
			fputc('/',g_state.output);
			fputc('*',g_state.output);
			g_state.ulstate = c_comment_state;
		}
		break;
		case '"':
		fputc('"',g_state.output);
		g_state.ulstate=string_comment_state;
		break;
		case EOF:
			g_state.ulstate=end_state;
		break;
		default:
			fputc(ch,g_state.output);
		break;
	}
}
void eventpro_cpp(char ch)
{
		char nextch;
		char thirdch;	
	switch(ch)
	{
	case EOF:
		fputc('*',g_state.output);
		fputc('/',g_state.output);
		g_state.ulstate = end_state;
		break;
	case '\n':
		fputc('*',g_state.output);
		fputc('/',g_state.output);
		g_state.ulstate = no_comment_state;
		fputc('\n',g_state.output);
		break;
	case '/':
		nextch=fgetc(g_state.input);
	if(nextch=='/'||nextch=='*') //  /////123
	{
		if(nextch=='/')
		{	thirdch=fgetc(g_state.input);
			if(thirdch=='/')
			{
				while(thirdch=fgetc(g_state.input)=='/');
						fputc(thirdch,g_state.output);
			}
			else            // /*123
			{
				fputc(' ',g_state.output);
				fputc(' ',g_state.output);
			fseek(g_state.input,-1,SEEK_CUR);
			}
		}
	}	
	break;
	case '*':	
		nextch=fgetc(g_state.input);
		if(nextch=='/')
		{
			fputc(' ',g_state.output);
			fputc(' ',g_state.output);
		}
		break;	
	default:
		fputc(ch,g_state.output);
		break;
	}
}

void eventpro_str(char ch)
{	
	char nextch;
	switch(ch)
	{
	case '/':
		nextch=fgetc(g_state.input);
		if(nextch=='/'||nextch=='*')
			if(nextch=='/')
			{
			fputc('/',g_state.output);
			fputc('/',g_state.output);
			}
			if(nextch == '*')
			{
				fputc('/',g_state.output);
				fputc('*',g_state.output);
			}
		break;

	case '*':	
		nextch=fgetc(g_state.input);
		if(nextch=='/')
		{
			fputc(' ',g_state.output);
			fputc(' ' ,g_state.output);
		}
		break;	
	case '"':
		fputc('"',g_state.output);
		g_state.ulstate=end_state;
	break;
	default:
		fputc(ch,g_state.output);
	break;
	
	}
}

void eventpro_c(char ch)
{
		char nextch;
	switch(ch)
	{
	case '*':
		nextch=fgetc(g_state.input);
		if(nextch == '/')
		{
		fputc('*',g_state.output);
		fputc('/',g_state.output);
		g_state.ulstate=no_comment_state;
		}
		else
		fputc(' ',g_state.output);
		break;
	case '/':
		nextch=fgetc(g_state.input);
		if(nextch == '/')
		{
		fputc(' ',g_state.output);
		fputc(' ',g_state.output);
		}
		break;
	case EOF:
		g_state.ulstate=end_state;
		break;
	default:
	fputc(ch,g_state.output);
	break;			
	}
}

