#include <stdlib.h>
#include <stdio.h>

int shellsort(int x[], int n, int incremento[], int numeric)
//numeric é o numero de interações
//incremento é o array dos incrementos
{
	int incr, j, k, span, temp;
	
	for (incr = 0; incr < numeric; incr++){
		span = incremento[incr];
		/* span eh o tamanho do incremento */
		
		for (j = span; j < n; j++){ //esse for é inserção simples, oq vai garantir a ordenação dentro dos subvetores
			temp = x[j];
		/*insere elemento x[j] em sua posição correta dentro de seu  subvetor*/
			for (k = j -span;  k >= 0 && temp < x[k]; k -= span)
				x[k+span] = x[k];
			x[k+span] = temp;
		}
	}
}

int main(){
	int y[] = {25,57,48,37,12,92,86,33};
	int n=8;
	int f;
	int numeric;
	int i[] = {5,3,1};
	numeric = 3;
	shellsort(y,n,i,numeric);
	for(f=0; f< n; f++)
		printf("%d ", y[f]);
} 
