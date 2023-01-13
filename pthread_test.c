#include <string.h>
#include <pthread.h>
#include <stdio.h>
#include <errno.h>


void *pthread(void *arg){
    
    while(1){
	sleep(1);
    }
    return;
}



int main(int argc, char * argv[]){

    pthread_t tid;
    int err = 0, count= 0;


    while(err == 0){
        err = pthread_create(&tid, NULL, pthread, NULL);
        count++;
	printf("count:[%d]\n", count);
    }

    printf("create thread error : %s\n", strerror(errno));
    printf("max number of thread within a process is : %d \n", count);

    getchar();

    return 0;
}
