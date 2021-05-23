#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#define thread_num  4

void *pointCount(void *param);
long long int size; 
long long int count = 0;
//declare a mutex clock
pthread_mutex_t lock;

int main(int argc, char* argv[]){
     
     //condition to chech the input
    if (argc != 2) {
        printf("Enter the number of points!\n");
        return -1;
    }
    if (atoll(argv[1]) < 0) {
        printf("Your point's number must be a positive interger number ! \n ");
        return -1;
    }

    //declare variable
    
    long long int sum = 0;
    size = atoll(argv[1])/thread_num;            
    pthread_t threads[thread_num];
    srand(time(NULL));

    //initialize mutex lock as defaults
    pthread_mutex_init(&lock,NULL);

    for(int i =0;i<thread_num;++i){
        pthread_create(&threads[i],NULL,pointCount,&count);
    }
    for(int i =0;i<thread_num;++i){
        pthread_join(threads[i],NULL);
    }

    //destroy the mutex lock
    pthread_mutex_destroy(&lock);

    double pi = (double)4*((double)count)/((double)atoll(argv[1]));
    printf("%f\n",pi);
    
    return 0;
    pthread_exit(0);
}

void* pointCount(void *param) {
    
    for(long long int i = 0; i <size; ++i) {
        double x = (double)rand()/(double)RAND_MAX;
        double y = (double)rand()/(double)RAND_MAX;
        double r = sqrt(y*y+x*x);

        pthread_mutex_lock(&lock);
        if(r <= 1) {
        
            count++;
        }
        pthread_mutex_unlock(&lock);
    }
    pthread_exit(0);
}


//using by command line "./pi_multi-thread [point's number]" .