#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void merge(int x[], int m1, int m2, int m3){
	
	int y[256];
	int apoint, bpoint, cpoint;
	
	apoint = m1;
	bpoint = m2+1;
	for(cpoint = m1; apoint <= m2 && bpoint <= m3; cpoint++){
		if(x[apoint]<x[bpoint])
			y[cpoint] = x[apoint+1];
		else
			y[cpoint]  =  x[bpoint++];
		}
	while(apoint  <=  m2)
		y[cpoint++]  =  x[apoint++];
	while(bpoint  <=  m3)
		y[cpoint++]  =  x[bpoint++];
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

int main(){

} 
