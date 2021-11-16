#include <stdio.h>
#include <string.h>

int isVowel (char c){
    return (c=='A' || c=='E' || c=='I' || c=='O' || c=='U' || c=='a' || c=='e' || c=='i' || c=='o' || c=='u'); 
}

int contaVogais (char *s){
    int count=0, i;
    for(i=0; *(s+i); i++)
        count += isVowel(*(s+i));
    return count;
}

int retiraVogaisRepAux (char *s){
    int i=0, j=0;
    const size_t N = strlen(s);
    char aux[N], c = '\0';

    for(; i<N; i++){
        if(!isVowel(s[i])){
            aux[j++] = s[i];
            c = '\0';
        }
        else{
            if(s[i]!=c){
                aux[j++] = s[i];
                c = s[i];
            }
        }
    }
    aux[j] = '\0';
    strcpy(s, aux);
    return (N-j);
}

int retiraVogaisRep (char *s){
    int i=0, j=0;
    char c = '\0';

    for(; s[i]; i++){
        if(!isVowel(s[i])){
            s[j++] = s[i];
            c = '\0';
        }
        else{
            if(s[i]!=c){
                s[j++] = s[i];
                c = s[i];
            }
        }
    }
    s[j] = '\0';
    return (i-j);
}

int duplicaVogaisAux (char *s){
    int i=0, j=0;
    const size_t N = strlen(s);
    char aux[2*N];

    for(; i<N; i++){
        if(!isVowel(s[i]))
            aux[j++] = s[i];
        else
            aux[j++] = aux[j++] = s[i];
    }
    aux[j] = '\0';
    strcpy(s, aux);
    return (j-N);
}

int duplicaVogais (char *s){
    int i=0, k;
    const size_t N = strlen(s);
    size_t tam = N;
    for(; i<tam; i++){
        if(isVowel(s[i])){
            tam++;
            s[tam] = '\0';
            for(k=tam-1; k>i; k--)
                s[k] = s[k-1];
            i++;
        }
    }
    return (tam-N);
}

int main(){   
    char s1 [100] = "uwu owo", s2[100] = "Estaa e umaa strinng coom duuuplicadoos", s3[100] = "plsh nm = yhzzczwb";
    int x;
    
    printf ("Testes\n\n");

    printf ("A string \"%s\" tem %d vogais\n", s1, contaVogais (s1));
    x = retiraVogaisRep (s1);
    printf ("Foram retiradas %d vogais, resultando em \"%s\"\n", x, s1);
    x = duplicaVogais (s1);
    printf ("Foram acrescentadas %d vogais, resultando em \"%s\"\n\n", x, s1);

    printf ("A string \"%s\" tem %d vogais\n", s2, contaVogais (s2));
    x = retiraVogaisRepAux (s2);
    printf ("Foram retiradas %d vogais, resultando em \"%s\"\n", x, s2);
    x = duplicaVogais (s2);
    printf ("Foram acrescentadas %d vogais, resultando em \"%s\"\n\n", x, s2);

    printf ("A string \"%s\" tem %d vogais\n", s3, contaVogais (s3));
    x = retiraVogaisRep (s3);
    printf ("Foram retiradas %d vogais, resultando em \"%s\"\n", x, s3);
    x = duplicaVogais (s3);
    printf ("Foram acrescentadas %d vogais, resultando em \"%s\"\n", x, s3);

    return 0;
}