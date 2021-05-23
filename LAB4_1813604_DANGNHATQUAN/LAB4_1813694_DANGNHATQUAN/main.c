#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "ex1.h"

int main(int argc, char* argv[]){
    
    void* ptr;
    printf("%d!\n",atoi(argv[1]));
    printf("%d!\n",atoi(argv[2]));
    ptr = aligned_malloc(atoi(argv[1]),atoi(argv[2]));
    if(ptr == NULL){
        printf("Fail!\n");
    }
    else {
        printf("%d Successfully!\n",(int)(int*)ptr);
    }

    aligned_free(ptr);

   
    return 0;
}