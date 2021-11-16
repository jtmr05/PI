#include <stdio.h>

void triangulo(int n){
	int i, j;
	for (i=1; i<=n; i++){
		for(j=0; j<i; j++)
			putchar('#');
		putchar('\n');
	}
	for (i=n-1; i>0; i--){
		for(j=0; j<i; j++)
			putchar('#');
		putchar('\n');
	}
}