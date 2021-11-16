#include "queue.h"

//1
/* void SinitQueue (SQueue q){
    if(!q){
        SQueue aux = malloc(sizeof *aux);
        q = aux;
    }
    q->front = 0;
    q->length = 0;
} */

void SinitQueue (SQueue *q){
    if(!(*q)){
        SQueue aux = malloc(sizeof *aux);
        (*q) = aux;
    }
    (*q)->front = 0;
    (*q)->length = 0;
}

//2
int SisEmptyQ (SQueue q){
    return (!(q->length > 0 && q->front < MAX));
}

//3
int Senqueue (SQueue q, int x){
    if((q->front + q->length) < MAX){
        q->values[q->length + q->front] = x;
        (q->length)++;
        return 0;
    }
    return 1;
}

//4
int Sdequeue (SQueue q, int *x){
    if(q->length > 0 && q->front < MAX){
        *x = q->values[(q->front)++];
        (q->length)--;
        return 0;
    }
    return 1;
}

//5
int Sfront (SQueue q, int *x){
    if(q->length > 0 && q->front < MAX){
        *x = q->values[q->front];
        return 0;
    }
    return 1;
}

//----------------------------------------------------------------------------------------

//1
void DinitQueue (DQueue *q){
    if(!(*q)){
        DQueue aux = malloc(sizeof *aux);
        aux->values = malloc(sizeof *aux->values * INIT_SIZE);
        aux->size = INIT_SIZE;
        (*q) = aux;
    }
    (*q)->front = 0;
    (*q)->length = 0;
}

//2
int DisEmptyQ (DQueue q){
    return (!(q->length > 0 && q->front < q->size));
}

//3
int Denqueue (DQueue q, int x){
    int r=0;
    if((q->front + q->length) >= q->size){
        printf("Reallocing queue...\n");
        int *aux = realloc(q->values, sizeof *aux * q->size * 2);

        q->values = aux;

        if(!aux)
            r=1;
        else
            q->size *= 2;
    }
    if(!r){
        q->values[q->length + q->front] = x;
        (q->length)++;
    }
    
    return r;
}

//4
int Ddequeue (DQueue q, int *x){
   if(q->length > 0 && q->front < q->size){
        *x = q->values[(q->front)++];
        (q->length)--;
        return 0;
    }
    return 1;
}

//5
int Dfront (DQueue q, int *x){
    if(q->length > 0 && q->front < q->size){
        *x = q->values[q->front];
        return 0;
    }
    return 1;
}

void freeDQueue(DQueue q){
    free(q->values);
    free(q);
}

//----------------------------------------------------------------------------------------

void ShowSQueue (SQueue q){
    int i, p;
    printf ("%d Items: ", q->length);
    for (i=0, p=q->front; i<q->length; i++) {
        printf ("%d ", q->values[p]);
        p = (p+1)%MAX;
    }
    putchar ('\n');
}

void ShowDQueue (DQueue q){
    int i, p;
    printf ("%d Items: ", q->length);
    for (i=0, p=q->front; i<q->length; i++) {
        printf ("%d ", q->values[p]);
        p = (p+1)%q->size;
    }
    putchar ('\n');
}
