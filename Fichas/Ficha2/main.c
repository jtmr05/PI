#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mult.h"
#include "mdc.h"
#include "fib.h"

int main(int argc, char** argv){

	if(argc<3){
		printf("Poucos argumentos!\n");
		return 1;
	}

	int fator, met;
	fator = atoi(argv[1]);
	met = atoi(argv[2]);

	switch(fator){

		case 1:{
			if(met>2 || met<1){
				printf("Método não existe!\n");
				return 1;
			}
			printf(">Multiplicação int por float (método %d)\n", met);

			int n;
			float m;
			printf("Introduza um inteiro não negativo: ");
			scanf("%d",&n);
			printf("Introduza um float: ");
			scanf("%f",&m);

			clock_t begin = clock();
			switch(met){

				case 1:{
					float r = multInt1(n,m);
					printf("%d*%f = %f\n", n, m, r);
					break;
				}

				case 2:{
					float r = multInt2(n,m);
					printf("%d*%f = %f\n", n, m, r);
					break;
				}
			}
			clock_t end = clock();
			double elapsed = ((double) (end-begin)) / CLOCKS_PER_SEC * 1000000;
			printf("%lf μs\n", elapsed);
			break;
		}

		case 2:{
			if(met>3 || met<1){
				printf("Método não existe!\n");
				return 1;
			}

			printf(">Máximo divisor comum (método %d)\n", met);

			int n1, n2;
			printf("Introduza um inteiro não negativo: ");
			scanf("%d",&n1);
			printf("Introduza outro inteiro não negativo: ");
			scanf("%d",&n2);

			clock_t begin = clock();
			switch(met){

				case 1:{
					int r = mdc1(n1,n2);
					printf("mdc(%d, %d) = %d\n", n1, n2, r);
					break;
				}

				case 2:{
					int r = mdc2(n1,n2);
					printf("mdc(%d, %d) = %d\n", n1, n2, r);
					break;
				}

				case 3:{
					int r = mdc3(n1,n2);
					printf("mdc(%d, %d) = %d\n", n1, n2, r);
					break;
				}

			}
			clock_t end = clock();
			double elapsed = ((double) (end-begin)) / CLOCKS_PER_SEC * 1000000;
			printf("%lf μs\n", elapsed);
			break;
		}

		case 3:{
			if(met>2 || met<1){
				printf("Método não existe!\n");
				return 1;
			}
			printf(">Sequência de Fibonnacci (método %d)\n", met);

			int n;
			printf("Introduza um inteiro positivo: ");
			scanf("%d",&n);

			clock_t begin = clock();
			switch(met){

				case 1:{
					int r = fib1(n);
					printf("%d-ésimo número de Fibonacci = %d\n", n, r);
					break;
				}

				case 2:{
					int r = fib2(n);
					printf("%d-ésimo número de Fibonacci = %d\n", n, r);
					break;
				}
			}
			clock_t end = clock();
			double elapsed = ((double) (end-begin)) / CLOCKS_PER_SEC * 1000000;
			printf("%lf μs\n", elapsed);
			break;
		}

		default:
			printf("Função não existe!\n");
	}

	return 0;
}