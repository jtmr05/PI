#include <stdlib.h>

typedef struct slist {
    int valor;
    struct slist * prox;
} *LInt;
    
typedef LInt Stack;

LInt newLInt (int x, LInt xs) {
    LInt r = malloc (sizeof *r);
    if (r) {
        r->valor = x; 
        r->prox = xs;
    }
    return r;
}

//1
void initStack (Stack *s){
    (*s) = calloc(1,sizeof **s);
}

//2
int SisEmpty (Stack s){
    return (s==NULL);
}

//3
int push (Stack *s, int x){
    Stack aux = *s;
    initStack(s);
    (*s)->valor = x;
    (*s)->prox = aux;
    return 0;
}

//4
int pop (Stack *s, int *x){
    if((*s)){
        Stack aux = (*s)->prox;
        *x = (*s)->valor;
        free(*s);
        (*s) = aux;
        return 0;
    }
    return 1;
}

//5
int top (Stack s, int *x){
    if(s){
        *x = s->valor;
        return 0;
    }
    return 1;
}



typedef struct queue {
    LInt inicio,fim;
} Queue;

//1
void initQueue (Queue *q){
    q->inicio = calloc(1,sizeof *q->inicio);
    q->fim = q->inicio;
}

//2
int QisEmpty (Queue q){
    return (q.inicio == NULL);
}

//3
int enqueue (Queue *q, int x){
    if(q){
        LInt new = malloc(sizeof *new);
        new->prox = NULL;
        new->valor = x;
        q->fim->prox = new;
        q->fim = q->fim->prox;
    }
    else{
        initQueue(q);
        q->inicio = x;
    }
    return 0;
}

//4
int dequeue (Queue *q, int *x){
    if(q->inicio){
        *x = q->inicio->valor;
        LInt aux = q->inicio->prox;
        free(q->inicio);
        if(!aux)
            q->fim = NULL;
        q->inicio = aux;
        return 0;
    }
    return 1;
}

//5
int front (Queue q, int *x){
    if(q.inicio){
        *x = q.inicio->valor;
        return 0;
    }
    return 1;
}