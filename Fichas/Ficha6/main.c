#include "stack.h"
#include "queue.h"
#include <stdio.h>

int main() {
    int i ; 
    
    SStack S1 = NULL;
    DStack D1 = NULL;

    SQueue Q1 = NULL;
    DQueue R1 = NULL;
    
    printf ("Testing Stacks .... \n");
    SinitStack (&S1);
    DinitStack (&D1);

    printf("SStack - ERROR pushing: ");
    for (i=0; i<10; i++){
        if (Spush (S1,i)) 
            printf ("%d; ", i);
    }
    putchar('\n');

    printf("DStack - ERROR pushing: ");
    for (i=0; i<42; i++){
        if (Dpush (D1,i)) 
            printf ("%d; ", i);
    }
    putchar('\n');

    ShowSStack (S1);
    ShowDStack (D1);
    
    printf ("Testing Queues .... \n");
    SinitQueue (&Q1);
    DinitQueue (&R1);

    printf("SQueue - ERROR pushing: ");
    for (i=0; i<15; i++){
        if (Senqueue (Q1,i)) 
            printf ("%d; ", i);
    }
    putchar('\n');

    printf("DQueue - ERROR pushing: ");
    for (i=0; i<42; i++){
        if (Denqueue (R1,i)) 
            printf ("%d; ", i);
    }
    putchar('\n');
    
    ShowSQueue (Q1);
    ShowDQueue (R1);

    free(S1);
    freeDStack(D1);
    free(Q1);
    freeDQueue(R1);
    return 0;
} 