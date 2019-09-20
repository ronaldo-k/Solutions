#include <stdio.h>

int m;

/*
int tm (int a) {
	if (a == 0) return 1;
	else {
		return 2 * tm(a-1) + 1; 
	}
}
*/

int id (int n, int k) {
	//printf("\nn = %d | k = %d | tm(n)/2 = %d",n,k,tm(n)/2);
	int tam=(1<<n);
	if(k == tam) {
		return n;
	}
	else if(k < tam) {
		return id(n-1,k);
	}
	else {
		return id(n-1,k - tam);
	}
}

int main() {
	scanf("%d",&m);
	printf("%c\n",'a'+id(25,m));
}