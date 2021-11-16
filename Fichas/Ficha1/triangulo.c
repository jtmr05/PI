#include <stdio.h>
#include <stdlib.h>

void triangulo(int n);

int main(int argc, char *argv[]){

	if (argc==1){
		printf("Nenhum argumento!\n");
		return 1;
	}

	int fator;
	
	fator = atoi(argv[1]);

	triangulo(fator);
	return 0;
}