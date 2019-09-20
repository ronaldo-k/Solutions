#include <stdio.h>

const int maxn = 10010;
int n,k,x[maxn],bit0[maxn],bitn[maxn];

void update(int a, int b) {
	while(a < maxn) {
		if(b == 0) {
			bit0[a] = 1;
			a += a & -a;
		}
		else if(b < 0) {
			bitn[a] = 1;
			a += a & -a;
		}
	}
}

char query(int a, int b) {
	int nc = 0;
	int c = b;
	while(b > a) {
		c--;
		if(bit0[c] == 1) {
			return '0';
		}
		if(bitn[c] == 1) {
			nc++;
		}
	}
	if(nc % 2 == 0) return '+';
	else return '-';
}

int main() {
	scanf("%d%d",&n,&k);
	for(int i = 0; i < n; i++) {
		scanf("%d",&x[i]); 
		if(x[i] == 0) bit0[i] = 1;
		else if(x[i] < 0) bitn[i] = 1;
	}
	for(int i = 0; i < k; i++) {
		char a;
		int ta, tb;
		scanf(" %c%d%d",&a,&ta,&tb);
		if(a == 'C') {
			update(ta,tb);
		}
		else if(a == 'P') {
			printf("\n>>>>>>>>>>>>>>> %c",query(ta,tb));
		}
	}
}