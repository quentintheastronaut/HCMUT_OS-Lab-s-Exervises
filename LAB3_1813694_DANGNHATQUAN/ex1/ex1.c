#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    pid_t pid ;
    pid = fork();

    if(pid == 0){
        
        FILE *f;
        f = fopen("numbers.txt","r");
        int count=0;
        while(!feof(f)){
            int value;
            fscanf(f,"%d\n",&value);
            if(value%2 == 0){
                count++;
            }
        }
        printf("%d\n",count);
        return 0;
    }

    pid = fork();
    if(pid == 0){
        
        FILE *f;
        f = fopen("numbers.txt","r");
        int count=0;
        while(!feof(f)){
            int value;
            fscanf(f,"%d\n",&value);
            if(value%3 == 0){
                count++;
            }
        }
        printf("%d\n",count);
        return 0;
    }

    pid = fork();
    if(pid == 0){
        
        FILE *f;
        f = fopen("numbers.txt","r");
        int count=0;
        while(!feof(f)){
            int value;
            fscanf(f,"%d\n",&value);
            if(value%5 == 0){
                count++;
            }
        }
        printf("%d\n",count);
        return 0;
    }



}