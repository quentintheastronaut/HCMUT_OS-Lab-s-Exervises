#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "ex1.h"

void *aligned_malloc(unsigned int size, unsigned int align){

    void *ptr;
    

    if(align <=0 ){
        return NULL;
    }
    else {
        double z = log((double)align)/log((double)2);
        double h = pow((double)2,z);
        if(h - align != 0){
            return NULL;
        }
    }

    if(size == 0){
        return NULL;
    }
    else {
        ptr = sbrk(0);
        int z = (int)(int*)ptr;
        if(z%align == 0){
            if(sbrk(size) == (void*)-1){
                return NULL;
            }
            else {
                return ptr;
            }
        }
        else {
            return NULL;
        }
    }
    
}

void *aligned_free(void *ptr){

    free(((void**)ptr)[-1]);
    
}