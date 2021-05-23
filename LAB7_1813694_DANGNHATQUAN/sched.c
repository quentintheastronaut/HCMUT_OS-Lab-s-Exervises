#include "queue.h"
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define TIME_UNIT   100

static struct pqueue_t in_queue;
static struct pqueue_t ready_queus;

static int load_done = 0;

static int timeslot;

void * cou(void * arg);

void * loader(void * arf);

void load_task();


int main(){
    pthread_t cpt_id;
    pthread_t loader_id;

    initialize_queue(&in_queue);
    initialize_queue(&ready_queue);

    load_task();

    pthread_create(&cpu_id, NULL, cpu, NULL);
    pthread_create(&loader_id,NULL,cpu,NULL);


    pthread_join(cpu_id,NULL);
    pthread_join(loader_id,NULL);

    pthread_exit(NULL);

}