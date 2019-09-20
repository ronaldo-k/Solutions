#include <stdio.h>

const int maxn = 100050;
int n;
int v[maxn];

int main() {
	scanf("%d",&n);
	for(int i = 0; i < n; i++) {
		int ta;
		scanf("%d",&ta);
		while(ta % 2 == 0) {
			ta /= 2;
		}
		while(ta % 3 == 0) {
			ta /= 3;
		}
		v[i] = ta;
	}
	for(int i = 0; i < n-1; i++) {
		if(v[i] != v[i+1]) {
			printf("\nNo");
			return 0;
		}
	}
	printf("\nYes");
}