
#include<stdio.h>
#include<unistd.h>
#include<iostream>
using namespace std;
int main(int argc,char *argv[])
{
	opterr = 0;
	char ch;
	while(ch = getopt(argc,argv,"ad:bc::")!=-1)
	{
		
		switch(ch)
		{
			case 'a':
			cout<<"this is a option"<<endl;
			break;	
			case 'd':
			cout<<"this is d option :d="<<optarg<<endl;
			break;
			case 'b':
			cout<<"this is b option"<<endl;
			break;
			case 'c':
			cout<<"this is c option :c="<<endl;
			break;
			case '?':
			cout<<"error"<<optopt<<endl;
			break;
		}
	}
	return 0;
}
