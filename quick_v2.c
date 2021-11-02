#include<stdio.h>
#include <stdlib.h>

void quick_sort(int *n, int menor, int maior) {
    int i, j, a, k;

    i = menor;
    j = maior;
    a = n[(menor + maior) / 2];

    while(i <= j) {
        while(n[i] < a && i < maior) {
            i++;
        }
        while(n[j] > a && j > menor) {
            j--;
        }
        if(i <= j) {
            k = n[i];
            n[i] = n[j];
            n[j] = k;
            i++;
            j--;
        }
    }

    if(j > menor) {
        quick_sort(n, menor, j);
    }
    if(i < maior) {
        quick_sort(n, i, maior);
    }
}

int main(){
	int y[] = {25,57,48,37,12,92,86,33};
	int n;
	int i;
	n=8;
	quick_sort(y,0,n-1);
	for(i=0; i< n; i++)
		printf("%d ", y[i]);	
} 
