#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

//Linked lists

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

//1
int length (LInt l){

    int count=0;
    for (; l; count++)
        l = l->prox;
    
    return count;
}

//2
void freeL (LInt l){
    if(!l) 
        return;

    freeL(l->prox);
    free(l);
}

void freeL (LInt l){
    LInt aux;

    while(l){
        aux = l->prox;
        free(l);
        l = aux;
   }
}

//3
void imprimeL (LInt l){
    
    while (l){
        printf("%d\n",l->valor);
        l = l->valor;
    }
}

//4
LInt reverseL (LInt l){
    LInt prev=NULL, aux;

    while(l){
        aux = l->prox;
        l->prox = prev;
        prev = l;
        l = aux;
    }
    return prev; //retornar l seria retornar NULL!
}

//5
void insertOrd (LInt *l, int x){

    while(*l && (*l)->valor < x)
        l = &((*l)->prox);
    
    LInt aux = *l;
    *l = malloc(sizeof **l);
    (*l)->valor = x;
    (*l)->prox = aux;
}

//6
int removeOneOrd (LInt *l, int x){

    int b = 1;
    while(*l && (*l)->valor < x)
        l = &((*l)->prox);
    
    if((*l) && (*l)->valor == x){
        b = 0;
        LInt prev = *l;
        (*l) = (*l)->prox;
        free(prev);
    }
   return b;
}

//7
void merge (LInt *r, LInt a, LInt b){

    while(a && b){
        if(a->valor < b->valor){
            *r = a;
            a = a->prox;
        }
        else{
            *r = b;
            b = b->prox;
        }
        r = &((*r)->prox);
    }

    if(!b)
        while(a){
            *r = a;
            a = a->prox;
            r = &((*r)->prox);
        }
    else
        while(b){
            *r = b;
            b = b->prox;
            r = &((*r)->prox);
        }

    *r = NULL;
}

//8
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    while(l){
        if(l->valor < x){
            *mx = l;
            mx = &(*mx)->prox;
        }
        else{
            *Mx = l;
            Mx = &(*Mx)->prox;
        }
        l = l->prox;
    }
    *Mx = *mx = NULL;
}

//9
LInt parteAmeio (LInt *l){
    LInt ret, *y = &ret;
    const size_t N = length(*l)>>1;
    int i=0;

    while(i<N){
        *y = *l;
        i++;
        (*l) = (*l)->prox;
        y = &((*y)->prox);
    }
    *y = NULL;
    return ret;
}

//10
int removeAll (LInt *l, int x){
    int count = 0;
    while(*l){
        if((*l)->valor == x){
            LInt prev = *l;
            (*l) = (*l)->prox;
            free(prev);
            count++;
        }
        else
            l = &((*l)->prox);
    }
    return count;
}

//11
int removeDups (LInt *l){
    while(*l){
        removeAll(&(*l)->prox, (*l)->valor);
        l = &((*l)->prox);
    }
    return 0;
}

//12
int removeMaiorL (LInt *l){
    int maior = (*l)->valor;
    LInt *ptr = l;
    l = &((*l)->prox);

    while(*l){
        if((*l)->valor > maior){
            maior = (*l)->valor;
            ptr = l;
        }
        l = &((*l)->prox);
    }
    LInt temp = *ptr;
    (*ptr) = (*ptr)->prox;
    free(temp);
    return maior;
}

//13
void init (LInt *l){
    while((*l)->prox)
        l = &((*l)->prox);
    
    LInt temp = *l;
    (*l) = NULL;
    free(temp);
}

//14
void appendL (LInt *l, int x){
    if(*l){
        while((*l)->prox)
            l = &((*l)->prox);
    
        (*l)->prox = calloc(1, sizeof *(*l)->prox);
        (*l)->prox->valor = x;
    }
    else{
        (*l) = calloc(1, sizeof **l);
        (*l)->valor = x;
    }
}

//15
void concatL (LInt *a, LInt b){
    while((*a))
        a = &((*a)->prox);
    
    *a = b;
}

//16
LInt cloneL (LInt l){
    LInt begin = NULL, new, ant = NULL;

    while(l){
        new = calloc(1, sizeof *new);
        if(!begin){
            begin = new;
        }
        new->valor = l->valor;
        if(ant)
            ant->prox = new;
        ant = new;
        l = l->prox;
    }
    
    return begin;
}

//17
LInt cloneRev (LInt l){
    LInt next=NULL, ant;

    if(!l)
        ant = NULL;
    else
        while(l){
            ant = malloc(sizeof *ant);
            ant->valor = l->valor;
            ant->prox = next;
            next = ant;
            l = l->prox;
        }

    return ant;
}

//18
int maximo (LInt l){
    int max = l->valor;
    l = l->prox;

    while (l){
        max = (l->valor > max) ? l->valor : max;
        l = l->prox;
    }
    return max;
}

//19
int take (int n, LInt *l){
    int i = 0;
    while(*l && i<n){
        l = &((*l)->prox);
        i++;
    }
    while(*l){
        LInt temp = *l;
        (*l) = (*l)->prox;
        free(temp);
    }
    return i;
}

//20
int drop (int n, LInt *l){
    int i = 0;
    LInt temp;
    while(*l && i<n){
        temp = *l;
        *l = (*l)->prox;
        free(temp);
        i++;
    }

    return i;
}

//21
LInt Nforward (LInt l, int N){
    int i = 0;
    if(l)
        while(i<N){
            i++;
            l = l->prox;
        }
    return l;
}

//22
int listToArray (LInt l, int v[], int N){
    int i = 0;
    while(l && i<N){
        v[i] = l->valor;
        l = l->prox;
        i++;
    }
    return i;
}

//23
LInt arrayToList (int v[], int N){

    int i = 0;
    LInt begin = NULL, new, ant = NULL;

    for(; i<N; i++){
        new = calloc(1, sizeof *new);
        new->valor = v[i];
        if(!begin)
            begin = new;
        if(ant)
            ant->prox = new;
        ant = new;
    }
    
    return begin;
}

//24
LInt somasAcL (LInt l){
    LInt begin = NULL, new, ant;
    if(l){
        new = calloc(1, sizeof *new);
        new->valor = l->valor;
        ant = begin = new;
        l = l->prox;
        while(l){
            new = calloc(1, sizeof *new);
            new->valor = l->valor + ant ->valor;
            ant->prox = new;
            ant = new;
            l = l->prox;
        }
    }
    return begin;
}

//25
void remreps (LInt l){
    if(!l)
        return;

    LInt *r = &l->prox, temp;
    int prev = l->valor;

    while(*r){
        if((*r)->valor == prev){
            temp = *r;
            *r = (*r)->prox;
            free(temp);
        }
        else{
            prev = (*r)->valor;
            r = &(*r)->prox;
        }
    }
}

//26
LInt rotateL (LInt l){
    LInt begin = l;

    if(begin){
        LInt temp = l;
        while(l->prox)
            l = l->prox;

        if(l!=temp){
            begin = temp->prox;
            l->prox = temp;
            temp->prox = NULL;
        }
    }

    return begin;
}

//27
LInt parte (LInt l){
    LInt ret, *y = &ret, *x = &l;
    int i = 0;

    while(*x){
        if(i%2){
            *y = *x;
            *x = (*x)->prox;
            y = &(*y)->prox;
        }
        else
            x = &(*x)->prox;
        
        i++;
    }
    *y = NULL;
    return ret;
}

//aprender a definir macros seu nabo
#define MAX(a,b) (a>b ? a : b)
#define MIN(a,b) (a<b ? a : b)

//Binary trees
typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

//28
int altura (ABin a){
    int alt = 0;

    if(a)
        alt += 1 + MAX(altura(a->esq), altura(a->dir));
    
    return alt;
}

//29
ABin cloneAB (ABin a){
    ABin new = NULL;

    if(a){
        new = malloc(sizeof *new);
        new->valor = a->valor;
        new->esq = cloneAB(a->esq);
        new->dir = cloneAB(a->dir);
    }

    return new;
}

//30
void mirror (ABin *a){
    if(!(*a))
        return;
    
    ABin temp = (*a)->esq;
    (*a)->esq = (*a)->dir;
    (*a)->dir = temp;
    mirror(&((*a)->esq));
    mirror(&((*a)->dir));
}

//31
void inorder (ABin a, LInt *l){

    if(a){
        inorder(a->esq, l);
        while(*l)
            l = &((*l)->prox);

        *l = malloc(sizeof **l);
        (*l)->valor = a->valor;
        l = &((*l)->prox);
        inorder(a->dir, l);
    }
    else
        *l = NULL;
}

//32
void preorder (ABin a, LInt *l){

    if(a){
        *l = malloc(sizeof **l);
        (*l)->valor = a->valor;
        l = &((*l)->prox);

        preorder(a->esq, l);
        while(*l)
            l = &((*l)->prox);
        preorder(a->dir, l);
    }
    else
        *l = NULL;
}

//33
void posorder (ABin a, LInt *l){

    if(a){
        posorder(a->esq, l);
        while(*l)
            l = &((*l)->prox);

        posorder(a->dir, l);
        while(*l)
            l = &((*l)->prox);

        *l = calloc(1, sizeof **l); //para NULLar o prox
        (*l)->valor = a->valor;
    }
    else
        *l = NULL;
}

//34
int depth (ABin a, int x){
    int ret = -1;
    
    if(a){
        if(x == a->valor)
            ret = 1;
        else{
            int esq = depth(a->esq, x);
            int dir = depth(a->dir, x);
            
            if(esq!=-1 && dir!=-1)
                ret = 1 + MIN(esq, dir);
            else if(esq!=-1 || dir!=-1)
                ret = 1 + MAX(esq, dir);
        }
    }
    return ret;
}

//35
int freeAB (ABin a){
    int count = 0;

    if(a){
        count = 1 + freeAB(a->esq) + freeAB(a->dir);
        free(a);
    }

    return count;
}

//36
int pruneAB (ABin *a, int l){
    int count;

    if(!(*a))
        count = 0;
    else{
        if(l==0){
            count = 1 + pruneAB(&(*a)->esq, 0) + pruneAB(&(*a)->dir, 0);
            free(*a);
            *a = NULL;
        }
        else
            count = pruneAB(&(*a)->esq, l-1) + pruneAB(&(*a)->dir, l-1);
    }
    return count;
}

//37
int iguaisAB (ABin a, ABin b){
    int boolean = 1;
    
    if(a || b){
    
        if((a && !b) || (!a && b))
            boolean = 0;
            
        else
            boolean = (a->valor == b->valor && iguaisAB(a->esq, b->esq) && iguaisAB(a->dir, b->dir));
    }
    return boolean;
}

//38
LInt nivelL (ABin a, int n){
    LInt begin, *r = &begin;

    if(!a)
        *r = NULL;
    else{
        if(n==1){
            *r = malloc(sizeof **r);
            (*r)->valor = a->valor;
            (*r)->prox = NULL;
        }
        else{
            *r = nivelL(a->esq, n-1);
            while(*r)
                r = &((*r)->prox);
            *r = nivelL(a->dir, n-1);
        }
    }
    return begin;
}

//39
int nivelV (ABin a, int n, int v[]){
    int i = 0;
    if(a){
        if(n==1)
            v[i++] = a->valor;
        else{
            i = nivelV(a->esq, n-1, v);
            i += nivelV(a->dir, n-1, v+i);
        }
    }

    return i;
}

//40
int dumpAbin (ABin a, int v[], int N){
    int i = 0;
    if(a){
        int e = dumpAbin(a->esq, v, N);
        if(e<N){
            v[e] = a->valor;
            int d = dumpAbin(a->dir, v+e+1, N-e-1);
            i = d+e+1;
        }
        else
            i = e;
    }
    return i;
}

//41
ABin somasAcA (ABin a){
    ABin new = NULL;
    if(a){
        new = malloc(sizeof *new);
        new->valor = a->valor;

        ABin e = somasAcA(a->esq);
        ABin d = somasAcA(a->dir);
        if(e)
            new->valor += e->valor;
        if(d)
            new->valor += d->valor;

        new->esq = e;
        new->dir = d;
    }

    return new;
}

//42
int contaFolhas (ABin a){
    int count = 0; //podia usar-se static
    if(a){
        if(!(a->esq) && !(a->dir))
            count++;
        else{
            count += contaFolhas(a->esq); //e aqui removia-se estes 'count +='
            count += contaFolhas(a->dir); //idem
        }
    }
    return count;
}

//43
ABin cloneMirror (ABin a){
    ABin new = NULL;
    if(a){
        new = malloc(sizeof *new);
        new->valor = a->valor;
        new->esq = cloneMirror(a->dir);
        new->dir = cloneMirror(a->esq);
    }
    return new;
}

//44
//método recursivo
int addOrd (ABin *a, int x){
    int b = 0;
    if(*a){
        if((*a)->valor == x)
            b = 1;
        else if((*a)->valor < x)
            b = addOrd(&(*a)->dir, x);
        else 
            b = addOrd(&(*a)->esq, x);
    }
    else{
        *a = malloc(sizeof **a);
        (*a)->valor = x;
        (*a)->esq = (*a)->dir = NULL;
    }
    return b;
}

//método iterativo
int addOrd (ABin *a, int x){
    int b = 0;
    while(*a && !b){
        if((*a)->valor == x)
            b = 1;
        else if((*a)->valor < x)
            a = &(*a)->dir;
        else 
            a = &(*a)->esq;
    }
    if(!b){
        *a = malloc(sizeof **a);
        (*a)->valor = x;
        (*a)->esq = (*a)->dir = NULL;
    }
    
    return b;
}

//45
int lookupAB (ABin a, int x){
    int b = 0;
    if(a){
        if(a->valor == x)
            b = 1;
        else if(a->valor < x)
            b = lookupAB(a->dir, x);
        else
            b = lookupAB(a->esq, x);
    }
    return b;
}

//46
int depthOrd (ABin a, int x){
    int level = -1, aux;
    if(a){
        if(a->valor == x)
            level = 1;
        else{
            if(a->valor < x)
                aux = depthOrd(a->dir, x); 
            else
                aux = depthOrd(a->esq, x);
            
            if(aux!=-1)
                level = 1 + aux;
        }
    }
    return level;
}

//47
int maiorAB (ABin a){
    int maior = a->valor;
    
    while(a->dir){
        a = a->dir;
        maior = a->valor;
    }

    return maior;
}

//48
void removeMaiorA (ABin *a){
    ABin temp;
    if(*a){
        while((*a)->dir)
            a = &(*a)->dir;
        
        temp = (*a)->esq;
        free(*a);
        *a = temp;
    }
}

//49
int quantosMaiores (ABin a, int x){
    int count = 0;
    if(a){
        if(a->valor <= x)
            count += quantosMaiores(a->dir, x);
        else 
            count += 1 + quantosMaiores(a->esq, x) + quantosMaiores(a->dir, x);
    }
    return count;
}

//50
void listToBTree (LInt l, ABin *a){
    LInt *trav = &l;
    if(l){
        int mid = length(l)>>1;
        while(mid>0){
            mid--;
            trav = &(*trav)->prox;
        }
        *a = calloc(1, sizeof **a);
        (*a)->valor = (*trav)->valor;
        
        LInt next = (*trav)->prox;  
        *trav = NULL;              //isto previne erros de cálculo do mid
        
        listToBTree(l, &(*a)->esq);
        listToBTree(next, &(*a)->dir);
    }
    else
        *a = NULL;
}

//51
int deProcuraAux(ABin a, int max, int min){
    int b = 1;
    
    if(a){
        if(a->valor > max || a->valor < min)
            b = 0;
        
        b = deProcuraAux(a->esq, a->valor - 1, min) &&  //no repeated values, therefore
            deProcuraAux(a->dir, max, a->valor + 1) &&  // -1 ou +1, conforme
            b;
    }
    return b;
}

int deProcura (ABin a){
    return deProcuraAux(a, INT_MAX, INT_MIN);
}