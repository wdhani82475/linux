#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<fcntl.h>
#ifndef _PTHREAD_RWLOCK_H_
#define _PTHREAD_RWLOCK_H_

enum {
		EINVAL=1;		
	}

typedef struct{
		pthread_mutex_t rw_mutex;
		pthread_cond_t rw_condreaders;
		pthread_cond_t rw_condwriters;
		int rw_magic;
		int rw_nwaitreaders;
		int rw_nwaitwriters;
		int rw_refcount;

}pthread_rwlock_t;


#define RW_MAGIC 0X1234567

#define PTHREAD_RWLOCK_INITIALIZER { PTHREAD_MUTEX_INITIALIZER,\
									PTHREAD_COND_INITIALIZER,\
									PTHREAD_COND_INITIALIZER,\
									RW_MAGIC,0,0,0}



//pthread_rwlock_init(pthread_rwlock_t *rwlock);
int pthread_rwlock_rdlock(pthread_rwlock_t *rw);
int pthread_rwlock_wrlock(pthread_rwlock_t *rw);
int pthread_rwlock_unlock(pthread_rwlock_t *rw);


#endif 
