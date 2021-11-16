#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char *argv[]){

	if (argc==1){
		printf("Nenhum argumento!\n");
		return 1;
	}

	int fator, i, j;
	
	fator = atoi(argv[1]);

	for (i=0; i<fator; i++){
		for(j=0; j<fator; j++)
			printf("#");
		printf("\n");
	}
	return 0;
}