#include<stdio.h>
#include <stdlib.h>

void quicksortz(int x[], int lb, int rb)
{
	//lb = left
	//rb = right
	int i, j;
	j = partition(x,lb,rb);
	printf("%d", x[rb]);
	printf("\noiii");
	if(lb>rb)
		printf("\naaaa");
	if(j > lb) {
        quicksortz(x, lb, j-1);
    }
    if(i < rb) {
        quicksortz(x, j+1, rb);
    }
}

int partition(int x[], int lb, int rb)
{
	int a, down, up, k;
	a = x[lb];
	up = rb; down = lb;
	while (down < up) {
		while (x[down] <= a && down < rb)
			down++;
		while (x[up] > a)
			up--;
		if(lb <= rb) {
            k = x[lb];
            x[lb] = x[rb];
            x[rb] = k;
            lb++;
            rb--;
        }
	}
	x[lb] = x[up];
	x[up] = a;
	return up;
} 


int main(){
	int y[] = {25,57,48,37,12,92,86,33};
	int n = 8;
	int i;
	quicksortz(y,0,n-1);	
} 
