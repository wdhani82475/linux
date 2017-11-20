#ifndef _CACL_H
#define _CACL_H

#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>


 enum oper{ADD,SUB,MUL,DIV,MOD,QUIT};
 typedef struct {
		 op1;
		 op2;
		 oper;
		 }calc;




#endif //_CACL_
