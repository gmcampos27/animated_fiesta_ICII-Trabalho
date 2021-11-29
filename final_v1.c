#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>

int imprimeMenu() {
	int opcao;
	
    printf("================================================================\n");
    printf("|            Escolha o programa que deseja executar            |\n");
    printf("================================================================\n");
    printf("| Opções:                                                      |\n");
    printf("|                                                              |\n");
    printf("| 1) Mergesort                                                 |\n");
    printf("| 2) Shellsort                                                 |\n");
    printf("| 3) Sair                                                      |\n");
    printf("|______________________________________________________________|\n");
    printf("  Pressione a opção desejada: ");
    
    scanf("%d", &opcao);
    return opcao;

}

void merge(int x[], int m1, int m2, int m3){
	
	int y[256];
	int apoint, bpoint, cpoint;
	int i;
	
	apoint = m1;
	bpoint = m2+1;
	for(cpoint = m1; apoint <= m2 && bpoint <= m3; cpoint++){
		if(x[apoint]<x[bpoint]){
			y[cpoint] = x[apoint];
			apoint++;
		}
		else
			y[cpoint]  =  x[bpoint++];
		}
	while(apoint  <=  m2)
		y[cpoint++]  =  x[apoint++];
	while(bpoint  <=  m3)
		y[cpoint++]  =  x[bpoint++];
	for(i=m1; i<=m3; i++)
		x[i]=y[i];
}

void mergesort(int *A, int e, int d){
	int q;
	
	if(e<d){
		q = floor((e+d)/2);
		mergesort(A,e,q);
		mergesort(A,q+1,d);
		merge(A,e,q,d);
	}
}

int shellsort(int x[], int n, int incremento[], int numeric)
//numeric é o numero de interações
//incremento é o array dos incrementos
{
	int incr, j, k, span, temp;
	
	for (incr = 0; incr < numeric; incr++){
		span = incremento[incr];
		/* span eh o tamanho do incremento */
		//x[0+span]
		
		for (j = span; j < n; j++){ //esse for é inserção simples, oq vai garantir a ordenação dentro dos subvetores
			temp = x[j];
		/*insere elemento x[j] em sua posição correta dentro de seu  subvetor*/
			for (k = j - span;  k >= 0 && temp < x[k]; k -= span)
				x[k+span] = x[k];
			x[k+span] = temp;
		}
	}
}


int main(){
	int opcao;
	int i, n, numeric, A[25];
	//A[], i, n -> todos
	//numeric, B[] -> shellsort
	int B[] = {5,3,1};
	numeric = 3;
	    
	setlocale(LC_ALL, "Portuguese");

    opcao = imprimeMenu();
  while(opcao != 3){
  	switch(opcao){
    	case 1:
        printf("Quantos elementos deseja inserir? ");
  	 	scanf("%d",&n);

   		printf("Insira %d elementos: ", n);
   		printf("\n");
   		for(i=0;i<n;i++)
      		scanf("%d",&A[i]);
      	
      	mergesort(A,0,n-1);
      	printf("Ordem dos elementos: ");
   		for(i=0;i<n;i++){
      		printf(" %d",A[i]);
      	}
      	printf("\n");
      	
        break;
       case 2: 
		printf("Quantos elementos deseja inserir? ");
   		scanf("%d",&n);

   		printf("Insira %d elementos: ", n);
   		printf("\n");
   		for(i=0;i<n;i++)
      		scanf("%d",&A[i]);
      	
      	shellsort(A,n,B,numeric);
      	printf("Ordem dos elementos: ");
   		for(i=0;i<n;i++){
      		printf(" %d",A[i]);
		}
		printf("\n");
        break;
	}
	opcao = imprimeMenu();
  }   
	
   return 0;
}
