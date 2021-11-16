#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula{
    char *palavra;
    int ocorr;
    struct celula *prox;
} *Palavras;

//1
void libertaLista (Palavras l){
    while(l){
        Palavras aux = l->prox;
        //free(l->palavra);
        free(l);
        l = aux;
    }
}

//2
int quantasP (Palavras l){
    int count=0;
    while(l){
        count++;
        l=l->prox;
    }
    return count;
}

//3
void listaPal (Palavras l){
    while(l){
        printf("'%s' - ocorre %d vezes\n", l->palavra, l->ocorr);
        l = l->prox;
    }
}

//4
char* ultima (Palavras l){
    char* aux;
    if(!l)
        aux = NULL;
    else{
        while(l->prox) l = l->prox;
        aux = l->palavra;
    }
    return aux;
}

//5
Palavras acrescentaInicio (Palavras l, char *p){
    Palavras new = malloc(sizeof *new);
    new->palavra = p;
    new->ocorr = 1;
    new->prox = l;
    return new;
}

//6
Palavras acrescentaFim (Palavras l, char *p){
    Palavras new = malloc(sizeof *new);
    Palavras ret;
    new->palavra = p;
    new->ocorr = 1;
    new->prox = NULL;
    
    if(l){
        ret = l;
        while(l->prox) l = l->prox;
        l->prox = new;
    }
    else
        ret = new;
    
    return ret;
}

//7
Palavras acrescenta (Palavras l, char *p){
    Palavras begin = l;
    Palavras ret = l;
    int boolean = 1;

    while(l && boolean){
        if(!strcmp(l->palavra, p)){
            l->ocorr++;
            boolean = 0;
        }
        else
            l = l->prox;
    }
    
    ret = (boolean) ? acrescentaInicio(begin, p) : l;

    return ret;
}

//8
struct celula* maisFreq (Palavras l){
    int max=-1;
    Palavras ret = NULL;

    while(l){

        if(l->ocorr > max){
            ret = l;
            max = l->ocorr;
        }
        l = l->prox;
    }

    return ret;
}