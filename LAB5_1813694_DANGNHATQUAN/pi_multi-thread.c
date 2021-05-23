#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define thread_num  4

void *pointCount(void *param);
long long int size; 

int main(int argc, char* argv[]){

    long long int count[thread_num];
     
    if (argc != 2) {
        return -1;
    }
    if (atoll(argv[1]) < 0) {
        
        return -1;
    }
    long long int sum = 0;
    size = atoll(argv[1])/thread_num;            
    pthread_t threads[thread_num];
    srand(time(NULL));
    
    for(int i =0;i<thread_num;++i){
            pthread_create(&threads[i],NULL,pointCount,&count[i]);
            pthread_join(threads[i],NULL);
            sum+= count[i];
    }
   
    double pi = (double)4*((double)sum)/((double)atoll(argv[1]));
    printf("%f\n",pi);
    

   
    return 0;
    pthread_exit(0);
}

void* pointCount(void *param) {
    long long int* n = (long long int*)param;
    for(long long int i = 0; i <size; ++i) {
        double x = (double)rand()/(double)RAND_MAX;
        double y = (double)rand()/(double)RAND_MAX;
        double r = sqrt(y*y+x*x);
        if(r <= 1) *n = *n + 1;
    }
    pthread_exit(0);
}