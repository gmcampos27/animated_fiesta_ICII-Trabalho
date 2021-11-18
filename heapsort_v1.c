#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int parent(int i){ //defirnir o nó pai
	return(floor(i/2));
}

int left(int i){ //definir o filho da esquerda
	return(2*i);
}

int right(int i){ //definir o filho da direita
	return(2*i+1);
}

void swap(int *x, int *y){ 
   int temp;
   temp=*x;
   *x=*y;
   *y=temp;
}

void HEAPIFY(int A[], int heapsize, int i){ //tornar a árvore com raíz i um heap
	int l, r, largest;
	l = left(i);
	r = right(i);
	if ((l <= heapsize) && (A[l] > A[i])){
		largest = l;}
	else
		largest = i;
	if ((r <= heapsize) && (A[r] > A[largest]))
		largest = r;
	if (largest != i){
		swap(&A[i], &A[largest]);         /* troca a posicao dos elementos */
		HEAPIFY(A, heapsize, largest);	
		}
	return;
}

void BUILDHEAP(int *A,  int heapsize){ //vai utilizar Heapfy para fazer heap em toda árvore
	int i;
	for (i = floor(heapsize/2); i > 0; i--)
		HEAPIFY(A, heapsize, i);
}

void HEAPSORT(int *A, int heapsize){
	int i;
	BUILDHEAP(A, heapsize);
	for (i = heapsize; i > 1; i--){
		swap(&A[1], &A[i]);
		heapsize--;
		HEAPIFY(A, heapsize, 1);
	}
}

int main(){
	int A[]={4,1,3,5,7,2,6,9,8,10};
	int i;
	int n=10;
	HEAPSORT(A, n);
	for(i=0; i< n; i++)
		printf("%d ", A[i]);
	return(0);
} 

