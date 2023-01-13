#include "pthread_creat.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>
#include <time.h>

/*****************************************
 * int pthread_create(
 *		pthread_t *restrict tidp, // The memory unit pointed to by the newly created thread ID
 *		const pthread_attr_t *restrict attr, // Thread property , which is null by default
 *		void *(*start_rtn)(void*), // new create thread run , begin here
 *		void *restrict arg //The default is null , if the above function requires parameters , put the parameters into the structure and pass the address as arg
 * )
 */


int aaa = 0;


void get_time_now(){

    struct timeval t;
    gettimeofday(&t, NULL);
    struct tm *t1 = localtime(&t.tv_sec);
    printf("%04d-%02d-%02d %02d:%02d:%02d.%03ld.%03ld\n",
	t1->tm_year+1900,
	t1->tm_mon+1,
	t1->tm_mday,
	t1->tm_hour,
	t1->tm_min,
	t1->tm_sec,
	t.tv_usec/1000,
	t.tv_usec%1000);
    return ;
}


void print_id(char *s){

    pid_t pid;
    pthread_t tid;

    pid = getpid(); // get process id
    tid = pthread_self(); // get thread id
    aaa++;
    printf("%s pid:[%lu] tid:[%lx] aaa:[%d]\n", s, pid, tid, aaa);

    return ;
}


void *thread_func(void *arg){

    printf("this is thread function!\n");
    
    while(1){
	print_id(arg);
	get_time_now();
	sleep(5);
    }

    return ;
}


void *thread_func1(thread_func1_t * p){
    
    pid_t pid;
    pthread_t tid;
  
    printf("a-->%d, b-->%d\n",p->a,p->b);
    
    while(1){
    
    	pid = getpid();
	tid = pthread_self();
        aaa--;
        printf("second thread: pid:[%lu] tid:[%lx] aaa:[%d] a:[%d] b:[%d]\n", pid, tid, aaa, p->a, p->b);
	get_time_now();
	sleep(5);
	
    }
    
    return ;
}


int main(int argc, char * argv[]){

    pthread_t tid;
    pthread_t tid1;
    pthread_t tid2;
    int res = 0;
    exp_t g_exp_t;


    res = pthread_create(&tid, NULL, (void *)thread_func, "first thread");
    if(res != 0){
	printf("create pthread 1 fail!\n");
	return 1;
    }
    
    thread_func1_t thread_func1_para;
    thread_func1_para.a = 1;
    thread_func1_para.b = 2;
    res = pthread_create(&tid1, NULL, (void *)thread_func1, &thread_func1_para);
    if(res != 0){
	printf("create pthread 2 fail!\n");
	return 1;
    }
    res = pthread_create(&tid2, NULL, (void *)thread_func, "third thread");
    if(res != 0){
	printf("create pthread 2 fail!\n");
	return 1;
    }    
    while(1){
	print_id("main thread");
	get_time_now();
	sleep(5);
    }

    return 0;
}
