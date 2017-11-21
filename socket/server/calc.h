#ifndef _CACL_H
#define _CACL_H

#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>


#define CMD_SIZE 5
typedef  enum{ADD,SUB,MUL,DIV,MOD,QUIT}ENUM_CALC;//枚举类型
typedef struct calcst
{
	int	op1;
	int op2;
	ENUM_CALC op;
}calcst;




#endif //_CACL_
