#include<stdio.h>
#include <stdlib.h>

quicksortz(int x[], int right, int left)
{
	int j;
	if (right > left) return;
	j = partition(x, right, left);
	quicksortz(x, right, j-1);
	quicksortz(x, j+1, left);
}

int partition(int x[], int right, int left)
{
	int a, down, up;
	//a=x[right]; //pior caso->O(n^2)
	a = (x[right]+x[left])/2; //melhor caso->O(n*log(n))
	up = left; down = right;
	while (down < up) {
		while (x[down] <= a && down < left)
			down++;
		while (x[up] > a)
			up--;
		if (down < up)
			swap(&x[down], &x[up]);
	}
	x[right] = x[up];
	x[up] = a;
	return up;
}

void swap(int *x, int *y){ 
   int temp;
   temp=*x;
   *x=*y;
   *y=temp;
}


int main(){
	int y[] = {55993640,5598742,3225489,559936400,55993641};
	int n=5;
	int i;
	quicksortz(y,0,n-1);
	for(i=0; i< n; i++)
		printf("%d ", y[i]);
} 
