#include <stdio.h> //!!!!!!!!!!!!!!!!!!!!!!!!

const int maxn = 100000;
int n,resp = 0,marc[maxn];

struct pessoa {
	int r, b, d;
};

pessoa v[maxn];


int main() {
	scanf("%d",&n);
	for(int i = 0; i < n; i++) {
		int tr, tb, td;
		scanf("%d%d%d",&v[i].r,&v[i].b,&v[i].d);
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(marc[i] == 0 && marc[j] == 0) {
				if(v[i].r < v[j].r && v[i].b > v[j].b){
					if(v[i].d > v[j].d) {
						marc[j] = 1;
						resp += v[i].d;
					}
					else {
						marc[i] = 1;
						resp += v[j].d;
					}
				}
				else {
					marc[i] = marc[j] = 1;
					resp += v[j].d + v[i].d;
				}
			}
		}
	}
	printf("\n%d",resp);
}