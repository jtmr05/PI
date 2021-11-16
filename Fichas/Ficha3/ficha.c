#include <stdio.h>

void swapM(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap(int v[], int i, int j){
    int temp = *(v+i);
    *(v+i) = *(v+j);
    *(v+j) = temp;
}

int soma (int v[], int N){
    int i=0, sum=0;
    for(; i<N; i++)
        sum += *(v+i);
    
    return sum;
}

void inverteArray (int v[], int N){
    int i, j;
    for(i=0, j=N-1; i<N/2; i++, j--)
        swapM(v+i,v+j);
}

void inverteArray2 (int v[], int N){
    int i, j;
    for(i=0, j=N-1; i<N/2; i++, j--)
        swap(v, i, j);
}

int maximum (int v[], int N, int *m){
    if (N<=0)
        return 1;
    *m = *v;
    for(int i=1; i<N; i++)
        *m = ((*(v+i))>(*m)) ? *(v+i) : (*m);

    return 0;
}

void quadrados (int q[], int N){
    *q=0;
    for(int i=1; i<N; i++)
        q[i] = (i-1)*(i-1) + 2*(i-1) + 1;
}

void pascal (int v[], int N){
    int i, j;
    *v = 1;
    for(i=1; i<N; i++){
        v[i] = 1;
        for(j=i-1; j>0; j--)
            v[j] = v[j] + v[j-1];
    }

}

int main(){
  /*  int a, b;
    printf("Introduza dois números: ");
    scanf("%d %d", &a, &b);
    printf("\nIntput: a = %d; b = %d\n", a, b);
    swapM(&a, &b);
    printf("Output: a = %d; b = %d\n", a, b); */

/*    int v[] = {1221,232,323,422,54,63,7,8322,9,10};
    printf("v = [");
    int i, j;
    for(i=0; i<10; i++)
        if (i<9)
            printf("%d, ",v[i]);
        else
            printf("%d]\n",v[i]); */

/*    printf("Introduza duas posições do array: ");
    scanf("%d %d", &i, &j);
    swap(v, i, j);
    printf("v = [");
    for(i=0; i<10; i++)
        if (i<9)
            printf("%d, ",v[i]);
        else
            printf("%d]\n",v[i]); */

 //   printf("Soma dos elementos de v = %d\n",soma(v,10));

 /*   inverteArray2(v,10);
    printf("v = [");
    for(i=0; i<10; i++)
        if (i<9)
            printf("%d, ",v[i]);
        else
            printf("%d]\n",v[i]); */
 /*   int m;
    maximum(v,10,&m);
    printf("Maior elemento de v = %d\n",m); */

    int a;
    printf("Introduza um número: ");
    scanf("%d", &a);

    for(int i=1; i<=a; i++){
        int v[i];
        pascal(v,i);
        
        for(int j=0; j<(a-i); j++)
            putchar(' ');

        for(int j=0; j<i; j++)
            printf("%d ",v[j]);

        putchar('\n');
    }

    return 0;
}