#include "stack.h"

//1 -- incorreta
/*void SinitStack (SStack s){
    if(!s)
        s = malloc(sizeof *s); //no caso de ser de s ser NULL, o que o seria sizeof *s?
    s->sp = 0;
} 

// -- incorreta (ou não...) [kinda incorreta...]
void SinitStack (SStack s){
    if(!s){
        SStack aux = malloc(sizeof *aux);
        s = aux;
    }
    s->sp = 0;
} */

//  -- correta -- as duas acima não alteram o apontador, daí a necessidade do parametro ser SStack*
void SinitStack (SStack *s){
    if(!(*s)){
        SStack aux = malloc(sizeof *aux);
        (*s) = aux;
    }
    (*s)->sp = 0;
}

//2
int SisEmpty (SStack s){
    return (s->sp == 0);
}

//3
int Spush (SStack s, int x){
    if(s->sp<MAX){
        s->values[(s->sp)++] = x;
        return 0;
    }
    return 1;
}

//4
int Spop (SStack s, int *x){
    if(s->sp>0){
        *x = s->values[(s->sp)--];
        return 0;
    }
    return 1;
}

//5
int Stop (SStack s, int *x){
    if(s->sp>0){
        *x = s->values[s->sp];
        return 0;
    }
    return 1;
}

//----------------------------------------------------------------------------------------

//1
/* void DinitStack (DStack s){
    if(!s){
        DStack aux = malloc(sizeof *aux);
        aux->values = malloc(sizeof *aux->values * INIT_SIZE);
        s = aux;
    }
    s->sp = 0;
    s->size = INIT_SIZE;
} */

void DinitStack (DStack *s){
    if(!(*s)){
        DStack aux = malloc(sizeof *aux);
        aux->values = malloc(sizeof *aux->values * INIT_SIZE);
        aux->size = INIT_SIZE;
        (*s) = aux;
    }
    (*s)->sp = 0;
}

//2
int DisEmpty (DStack s){
    return (s->sp == 0);
}

//3
int Dpush (DStack s, int x){
    int r=0;
    if(s->sp >= s->size){
        printf("Reallocing stack...\n");
        int* aux = realloc(s->values, sizeof *aux * s->size * 2);

        s->values = aux;

        if(!aux) 
            r=1;
        else
            s->size *= 2;
    }
    if(!r)
        s->values[(s->sp)++] = x;
    return r;
}

//4
int Dpop (DStack s, int *x){
    if(s->sp > 0){
        *x = s->values[(s->sp)--];
        return 0;
    }
    return 1;
}

//5
int Dtop (DStack s, int *x){
    if(s->sp > 0){
        *x = s->values[s->sp];
        return 0;
    }
    return 1;
}

void freeDStack (DStack s){
    free(s->values);
    free(s);
}

//----------------------------------------------------------------------------------------

void ShowSStack (SStack s){
    int i;
    printf ("%d Items: ", s->sp);
    for (i=s->sp-1; i>=0; i--) 
        printf ("%d ", s->values[i]);
    putchar ('\n');
}

// Stacks with dynamic arrays

int dupStack (DStack s) {
	int r = 0, i;
	int *t = malloc (2*s->size*sizeof(int));

	if (t == NULL) r = 1;
	else {
		for (i=0; i<s->size; i++) 
			t[i] = s->values[i];
		free (s->values);
		s->values = t;
		s->size*=2;
	}
	return r;
}

void ShowDStack (DStack s){
    int i;
    printf ("%d Items: ", s->sp);
    for (i=s->sp-1; i>=0; i--) 
        printf ("%d ", s->values[i]);
    putchar ('\n');
}
