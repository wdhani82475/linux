#include<unistd.h>
#include<iostream>
#include<stdio.h>
using namespace std;

int main(int argc,char*argv[])
{
	opterr = 0;
	char ch;
	while((ch=getopt(argc,argv,":a:b:c::x:hji")) != -1)
	{
			switch(ch)
			{
			case 'a':
					cout<<"this is a option : a="<<optarg<<endl;
					break;
			case 'b':
					cout<<"this is b option : b="<<optarg<<endl;
					break;
			case 'c':
					cout<<"this is c option : c= "<<optarg<<endl;
					break;
			case 'x':
					cout<<"this is x option : x="<<optarg<<endl;
					break;
			case 'h':
					cout<<"this is h option\n"<<endl;
					break;
			case 'j':
					cout<<"this is j option\n"<<endl;
			case 'i':
					cout<<"this is i option\n"<<endl;
					break;
			case ':':
					cout<<"less option"<<endl;
					break;
			case '?':
					cout<<"option error, invalid option is:"<<(char)optopt<<endl;
					break;
			}
	}
	return 0 ;
}
