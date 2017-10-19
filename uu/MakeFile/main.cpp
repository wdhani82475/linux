#include"min.h"
#include"max.h"
#include<iostream>
using namespace std;
#include<unistd.h>
int main()
{ 
	int a,b,c= 0,d= 0;
	cout<<"please input two nums:";
	cin>>a>>b;
	c=min(a,b);
	d=max(a,b);
	cout<<"the two nums of large"<<d<<endl;
	cout<<"the two nums of little"<<c<<endl;
	return 0;
	
}
