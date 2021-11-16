#include <stdio.h>
#include <time.h>

#define SIZE 10000

void bubbleSort(int[], int);
int isSorted(int [], int);
void minSort(int [], int);
void maxSort(int [], int);
void mergeSort(int [], int);
void insertionSort(int [], int);

int main(){
	int f, a[SIZE], i;
	clock_t begin, end;
	double elapsed;

	printf("1. BubbleSort\n2. MinSort\n3. MaxSort\n4. MergeSort\n5. InsertionSort\n> ");
	scanf("%d",&f);

	for(i=0; i<SIZE; i+=2)
		a[i] = 2*i;

	for(i=1; i<SIZE; i+=2)
		a[i] = 3*i;

	begin = clock();
	switch(f){
		case 1:
			bubbleSort(a, SIZE);
			break;

		case 2:
			minSort(a, SIZE);
			break;

		case 3:
			maxSort(a, SIZE);
			break;

		case 4:
			mergeSort(a, SIZE);
			break;

		case 5:
			insertionSort(a, SIZE);
			break;

		default:
			printf("Sort method does not exist!\n");
			f=0;
	}
	end = clock();

	if(f){
		elapsed = (double) (end - begin) / CLOCKS_PER_SEC;
		printf("%lf seconds\n", elapsed);
	}

	if(isSorted(a, SIZE))
		printf("Sim.\n");
	else
		printf("Não...\n");

	return 0;
}

int isSorted(int v[], int N){
	int i;

	for(i=0; i<N-1 && v[i]<=v[i+1]; i++);

	return(i==N-1);
}

void swap(int v[], int i, int j){
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int bubble(int v[], int N){

	int flag=1, i;

	for(i=0; i<N-1; i++)
		if(v[i]>v[i+1]){
			swap(v, i, i+1);
			flag=0;
		}

	return flag;
}

void bubbleSort(int v[], int N){
	int i=N;

	for(; i>0; i--){
		int f = bubble(v, i);
		if(f) break;
	}
}

void minSort(int v[], int N){

	int i, min, j;

	for(j=0; j<N; j++){
		min = j;
		for(i=j+1; i<N; i++)
			min = (v[i]<v[min]) ? i : min;
		swap(v, min, j);
	}
}

void maxSort(int v[], int N){

	int i, max, j;

	for(j=N-1; j>-1; j--){
		max = j;
		for(i=j-1; i>-1; i--)
			max = (v[i]>v[max]) ? i : max;
		swap(v, max, j);
	}
}

void merge (int a[], int na, int b[], int nb, int r[]){
    int i=0, j=0;

    while(i<na && j<nb){
        if(a[i]<b[j]){
            r[j+i] = a[i]; 
            i++;
        }
        else{
            r[j+i] = b[j]; 
            j++;
        }
    }

    if(i==na)
        for(; j<nb; j++)
            r[j+i] = b[j];
    else 
        for(; i<na; i++)
            r[j+i] = a[i];
}

void mergeSort(int v[], int N){

	if(N>1){
		int m = N/2, i, aux[N];

		mergeSort(v, m);
		mergeSort(v+m, N-m);
		merge(v, m, v+m, N-m, aux);
		for(i=0; i<N; i++)
			v[i] = aux[i];
	}
}

void insert(int v[], int N, int x){
	int i=0, j;

	for(; x>v[i]; i++);

	for(j=N; j>i; j--)
		v[j] = v[j-1];

	v[i] = x;
}

void insertionSort(int v[], int N){

	if(N<2) return;

	int x = v[N-1];
	insert(v, N-1, x);
	insertionSort(v, N-1);
}