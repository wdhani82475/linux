#ifndef _CALC_H
#define _CALC_H
#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#define CMD_SIZE 5
#define MAX_PTHREAD_NUM;

typedef enum {ADD,SUB,MUL,DIV,MOD,QUIT}calc_enum;
typedef struct calcst{
	
	int oper1;
	int oper2;
	calc_enum op;

	}calcst ;

typedef enum {IDLE,BUSY}WORK_STATE;

typedef struct thread_st
{
	int sockConn;
	WORK_STATE flag;
}thread_st;




#endif //_CALC_H
