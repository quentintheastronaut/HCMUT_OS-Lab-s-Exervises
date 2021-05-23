#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

int main(int argc, char* argv[]){

  
    

    if (argc != 2) {
        return -1;
    }
    if (atoll(argv[1]) < 0) {
        
        return -1;
    }
    long long int size = atoll(argv[1]);                                  
    long long int sum = 0;
    
    srand(time(NULL));
    
    for(long long int j = 0; j <size;j++) {
        double x = (double)rand()/(double)RAND_MAX;
        double y = (double)rand()/(double)RAND_MAX;
        double r = sqrt(y*y+x*x);
        if(r <= 1) sum++;
    }
   
    double pi = (double)4*((double)sum)/((double)atoll(argv[1]));
    printf("%f\n",pi);
    
    
    return 0;


}

