#include <stdio.h>

void triangulo(int n){
	int i, j;
	for (i=1; i<=n; i++){
		for(j=0; j<n-i; j++)
			putchar(' ');
		for(j=0; j<i; j++)
			putchar('#');
		for(j=i-1; j>0; j--)
			putchar('#');
		putchar('\n');
	}
}