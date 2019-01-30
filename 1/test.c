
#include"calc.h"
#include<stdio.h>
#include<unistd.h>
int main()
{
	printf("=====================\n");
	printf("=====请选择(1-5)=====\n");
	printf("=====================\n");
	int val,x,y;
	scanf("%d",&val);
	printf("请输入x和y\n");
	scanf("%d,%d",&x,&y);
	switch(val)
	{
		case 1:ADD(x,y);
		break;
		case 2 :SUB(x,y);
		break;
		default:printf("请重新选择。");
	}	
	return 0;
}
int ret;
int ADD(int x,int y )
{
	ret = x+y;
	printf("ret =%d\n",ret);
	return ret;
}
int SUB(int x,int y)
{
	ret = x-y;
	return ret;
}
