#include"pthread_rwlock.h"

int pthread_rwlock_rdlock(pthread_rwlock_t *rw)
{
	int result;
	if(rw->rw_magic !=	RW_MAGIC)
	{
		return EINVAL;
	}
	if((result=pthread_mutex_lock(rw->rw_mutex) )!=0)
			return result;
										//加锁成功，形成临界区
	while(rw->rw_refcunt<0||rw->rw_nwaitwriters>0)
	{
		rw->rw_nwaitreaders++;
		pthread_cond_wait(&rw->rw_condwriters,&rw->rw_mutex);
		rw->rw_nwaitreaders--;
		if(result != 0)
			break;
	}
	if(reasult == 0)
	{
		rw->rw_refcount++;
	}
	pthread_rwlock_unlock(&rw->rw_mutex);//解锁
	return (result);
}
