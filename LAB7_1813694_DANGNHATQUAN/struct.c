#ifndef STRUCTS_H
#define  STRUCTS_H

#include <pthread.h>

struct pcb_t {

    int arrival_time;
    int brust;

    int pid;
};

struct qitem_t {
    struct pcb_t * data;
    struct qitem_t * next;


};

struct pqueue_t {
    struct qitem_t * head;
    struct qitem_t * tail;

    pthread_mutex_t lock;

};

#endif