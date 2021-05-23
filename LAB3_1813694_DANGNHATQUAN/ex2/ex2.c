#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){

    int pid;
    pid = fork();                       //A make B
    if(pid == 0){
        
        pid = fork();                   //B make E
        if(pid > 0){
            pid = fork();               //B make F
        }
    }
    else {
        pid = fork();                   //A make C
        if(pid == 0){
            pid = fork();               //C make G
            if(pid == 0){
                pid = fork();       //G make I
            }
        }
        else{ 
        pid = fork();      //A make D
            
        }
    }

    

}




    