#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>

#define MAX 10
#define INIT_SIZE 10


struct staticStack{
    int sp;
    int values [MAX];
};

typedef struct staticStack *SStack;
typedef struct staticStack STACK;

void SinitStack (SStack *s);
int  SisEmpty (SStack s);
int  Spush (SStack s, int x);
int  Spop (SStack s, int *x);
int  Stop (SStack s, int *x);
void ShowSStack (SStack s);

//----------------------------------------------------------------------------------------

struct dinStack{
    int size; // guarda o tamanho do array values
    int sp;
    int *values;
};

typedef struct dinStack *DStack;
typedef struct dinStack DSTACK;

void DinitStack (DStack *s);
int  DisEmpty (DStack s);
int  Dpush (DStack s, int x);
int  Dpop (DStack s, int *x);
int  Dtop (DStack s, int *x);
void freeDStack (DStack s);
void ShowDStack (DStack s);

#endif