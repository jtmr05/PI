#include <stdio.h>

void dumpV (int v[], int N){
    int i;
    putchar ('{');
    for (i=0; i<N; i++) printf ("%2d ", v[i]);
    putchar ('}');
}

void simNao (int x){
    if (!x) printf (" não ");
}

int ordenado (int v[], int N){
    int i=0;
    while(i<N-1 && v[i]<v[i+1]) 
        i++;
    
    return (i==N-1);
}

void merge (int a[], int na, int b[], int nb, int r[]){
    int i=0, j=0;
    while(i<na && j<nb){
        if(a[i]<b[j]){
            r[j+i] = a[i]; 
            i++;
        }
        else{
            r[j+i] = b[j]; 
            j++;
        }
    }
    if(i==na)
        for(; j<nb; j++)
            r[j+i] = b[j];
    else 
        for(; i<na; i++)
            r[j+i] = a[i];
}

int partitionAux (int v[], int N, int x){
    int i=0, j=0, k=N-1, aux[N];

    for(; i<N; i++)
        if(v[i]>x)
            aux[k--] = v[i];
        else
            aux[j++] = v[i];
    

    for(i=0; i<N; i++)
        v[i] = aux[i];

    return j;
}

void swap(int v[], int i, int j){
    int temp = *(v+i);
    *(v+i) = *(v+j);
    *(v+j) = temp;
}

int partition (int v[], int N, int x){
    int i, a=0, b=N-1;

    while(a<b){
        while(a < N && v[a]<=x) a++;
        while(b >-1 && v[b] >x) b--;
        if(a<b) 
            swap(v, a, b);
    }
    return a;
}

int main() {  
    int a [15] = {10, 3,45,56, 8,23,13,42,77,31,18,88,24,45, 1},
        b [10] = { 4,12,34,45,48,52,61,73,84,87}, 
        c [10] = { 1, 3, 8,22,33,35,38,41,44,49}, 
        d [50];
    int x;
    
    printf ("Testes\n\n");

    printf ("O array "); dumpV(a,15);
    simNao (ordenado (a,15)); printf (" está ordenado\n");
    printf ("O array "); dumpV(b,10);
    simNao (ordenado (b,10)); printf (" está ordenado\n");
    
    printf ("\n\nMerge dos arrays "); dumpV (b,10);
    printf ("\ne                "); dumpV (c,10); 
    merge (b, 10, c, 10, d);
    printf ("\nresulta em       "); dumpV (d,20); 

    printf ("\n\n\nA partição do array  "); dumpV (a,15);
    printf ("\nusando 30 resulta em "); 
    x = partition (a,15,30); 
    dumpV (a,15); printf (" e retorna %d \n", x); 

    printf ("\nFim dos testes\n");
    return 0;
}