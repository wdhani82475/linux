#ifndef _CALC_H
#define _CALC_H
#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#define CMD_SIZE 5

typedef enum {ADD,SUB,MUL,DIV,MOD,QUIT}calc_enum;
typedef struct calcst{
	
	int oper1;
	int oper2;
	calc_enum op;

	}calcst ;



#endif //_CALC_H
