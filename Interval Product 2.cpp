#include <stdio.h>

const int maxn = 100010;
int bit0[maxn], bitn[maxn];

void update(int i, int a) {
	while(a < maxn) {
		int u = -a & a;
		printf("update: a = %d, -a & a = %d, u = %d",a,u,a+u);
		if(a == 0) {
			bit0[i] = 1;
			bitn[i] = 0;
		}
		else if(a < 0) {
			bitn[i] = 1;
			bit0[i] = 0;
		}
		a += u;
		printf("a = %d",a);
	}
}

int query(int ta, int tb) {
	return 0;
}

int main() {
	int n, m;
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++) {
		int ta;
		scanf("%d",&ta);
		if(ta < 0) {
			bit0[i] = 0;
			bitn[i] = 1;
		}
		else if(ta == 0) {
			bitn[i] = 0;
			bit0[i] = 1;
		} 
	}
	for(int i = 0; i < m; i++) {
		char tc;
		int ta,tb;
		scanf(" %c%d%d",&tc,&ta,&tb);
		if(tc == 'C') {
			for(int j = 0; j < ta; j++) {
				if(tb < 0) {
					bit0[i] = 0;
					bitn[i] = 1;
				}
				else if(tb == 0) {
					bitn[i] = 0;
					bit0[i] = 1;
				}
			} 
		}
		else query(ta,tb);	
	}
}