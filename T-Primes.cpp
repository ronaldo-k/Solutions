#include <stdio.h>
#include <math.h>

const int maxs = 10e6;
int n;
int c[maxs], marc[maxs];

void cc( int a ) {
	printf("cc.");
	if(marc[a] == 0) {
		int n = a+a;
		marc[a] = 2;
		while(n < maxs) {
			marc[n] = 1;
			n += a;
		}
	}
	else if(marc[a] == 1) cc(a+1);
}

int main() {
	for(int i = 0; i < maxs; i++) {
		c[i] = i;
		if(marc[i] == 0) cc(i);
	}
	scanf("%d",&n);
	for(int i = 0; i < n; i++) {
		long long int ta, sq;
		scanf("%lld",&ta);
		printf("ta = %lld",ta);
		sq = sqrt(ta);
		if(sq * sq == ta) {
			for(long long int i = 0; i < ta; i++) {
				printf("a");
				if(marc[i] == 2 && sq == c[i]) {
					printf("\nYES");
					break;
				}
			}
		}
		printf("\nNO");
	}
}