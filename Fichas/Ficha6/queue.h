#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdio.h>

#define MAX 10
#define INIT_SIZE 10

struct staticQueue{
    int front;
    int length;
    int values [MAX];
};

typedef struct staticQueue *SQueue;
typedef struct staticQueue QUEUE;

void SinitQueue (SQueue *q);
int  SisEmptyQ  (SQueue q);
int  Senqueue   (SQueue q, int x);
int  Sdequeue   (SQueue q, int *x);
int  Sfront     (SQueue q, int *x);
void ShowSQueue (SQueue q);

//----------------------------------------------------------------------------------------

struct dinQueue{
	int size;    // guarda o tamanho do array values
	int front;
	int length;
	int *values;
};

typedef struct dinQueue *DQueue;
typedef struct dinQueue DQUEUE;

void DinitQueue (DQueue *q);
int  DisEmptyQ  (DQueue q);
int  Denqueue   (DQueue q, int x);
int  Ddequeue   (DQueue q, int *x);
int  Dfront     (DQueue q, int *x);
void freeDQueue(DQueue q);
void ShowDQueue (DQueue q);

#endif