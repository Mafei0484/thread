#ifndef _PTHREAD_CREAT_H_
#define _PTHREAD_CREAT_H_

#define PACKED __attribute__((__packed__)) //内存对齐

typedef struct _exp_t_{
    int a;
    char b;

}PACKED exp_t;

typedef struct _thread_func_t_{
    int a;
    int b;

}PACKED thread_func1_t;



#endif
