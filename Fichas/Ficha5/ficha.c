#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT[6];
    float teste;
} Aluno;

void dumpV (int v[], int N){
    int i;
    for (i=0; i<N; i++) printf ("%d ", v[i]);
}

//1
int nota (Aluno a){
    float nota=0.0;
    int notaFinal;

    for(int i=0; i<6; i++)
        nota += a.miniT[i];

    nota/=2;
    nota += a.teste*0.7;

    notaFinal = (int) nota;

    notaFinal = (nota-notaFinal>0.5) ? notaFinal+1 : notaFinal;

    return notaFinal;
}

void imprimeAluno (Aluno *a){
    int i;
    printf ("%-5d %s (%d", a->numero, a->nome, a->miniT[0]);
    for(i=1; i<6; i++) printf (", %d", a->miniT[i]);
    printf (") %5.2f %d\n", a->teste, nota(*a));
}

//2
int procuraNumDes (int num, Aluno t[], int N){
    int i;
    for(i=0; i<N && num!=t[i].numero; i++);
    
    if (i==N) return -1;
    return i;
}

int procuraNum (int num, Aluno t[], int N){
    int i;
    for(i=0; i<N && num>t[i].numero; i++);
    
    if (i==N) return -1;
    if (t[i].numero==num) return i;
    return -1;
}

void swap(Aluno v[], int i, int j){
	Aluno temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int bubble(Aluno v[], int N){

	int flag=1, i;

	for(i=0; i<N-1; i++)
		if(v[i].numero>v[i+1].numero){
			swap(v, i, i+1);
			flag=0;
		}

	return flag;
}

//3
void ordenaPorNum (Aluno t[], int N){
    int i=N;

	for(; i>0; i--){
		int f = bubble(t, i);
		if(f) break;
	}
}

//4
void criaIndPorNum(Aluno t [], int N, int ind[]){
    int i, j, min, temp;
    int aux[N];

    for(i=0; i<N; i++)
        aux[i] = t[i].numero;

    for(j=0; j<N; j++){
		min = j;
		for(i=j+1; i<N; i++)
			min = (aux[i]<aux[min]) ? i : min;
		temp = aux[min];
        aux[min] = aux[j];
        aux[j] = temp;
	}

    for(i=0; i<N; i++)
        ind[i] = procuraNumDes(aux[i],t,N);
}

//5
void imprimeTurma (int ind[], Aluno t[], int N){
    int i;

    for(i=0; i<N; i++){
        imprimeAluno(t+ind[i]);
    }
}

int main() {
    Aluno Turma1 [7] = {{4444, "André", {2,1,0,2,2,2}, 10.5}
                       ,{6666, "Bruna", {2,2,2,1,0,0}, 12.5}
                       ,{8888, "Carla", {2,1,2,1,0,1}, 14.5}
                       ,{5555, "Diogo", {2,2,1,1,1,0},  8.5}
                       ,{2222, "Joana", {2,0,2,1,0,2},  3.5}
                       ,{7777, "Maria", {2,2,2,2,2,1},  5.5}
                       ,{3333, "Paulo", {0,0,2,2,2,1},  8.7}
                       };

    int indNome [7], indNum [7];
    int i;
    
    printf ("\n-------------- Testes --------------\n");
    
    //ordenaPorNum (Turma1, 7);
    //printf ("procura 2222: %d \n", procuraNum (2222, Turma1, 7));
    //printf ("procura 7777: %d \n", procuraNum (7777, Turma1, 7));

    for (i=0; i<7; imprimeAluno (Turma1 + i++));
    
    criaIndPorNum (Turma1, 7, indNum);
    dumpV(indNum, 7); putchar('\n');

    // printf ("procura 5555:%d \n",  procuraNumInd (5555, indNum, Turma1, 7));
    // printf ("procura 9999:%d \n",  procuraNumInd (9999, indNum, Turma1, 7));

    // criaIndPorNome (Turma1, 7, indNome);

    imprimeTurma (indNum, Turma1, 7);
    //imprimeTurma (indNome, Turma1, 7);

    printf ("\n---------- Fim dos Testes ----------\n");
    
    return 0;
}
