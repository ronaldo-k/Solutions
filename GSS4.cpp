#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

const int MAXN = 1e6 + 10;
int n, q;
long long int input[MAXN];int casos = 1;

struct node {
	long long int soma, lz;
};

struct node seg[4 * MAXN];

//----------------------//

void merge(int pos) {
	//printf("MERGE: pos = %d\n", pos);
	int e = 2 * pos, d = e + 1;
	
	if(seg[e].lz == 1 && seg[d].lz == 1) seg[pos].lz = 1;
	else seg[pos].lz = 0;
	seg[pos].soma = seg[e].soma + seg[d].soma;
}

void build(int pos, int ini, int fim) {
	//printf("BUILD: pos = %d, ini = %d, fim = %d\n", pos, ini, fim);
	if(ini == fim) {
		seg[pos].soma = input[ini];
		if(seg[pos].soma == 1) seg[pos].lz = 1;
		else seg[pos].lz = 0;
		return;
	}
	
	int m = (ini + fim) / 2;
	int e = 2 * pos, d = e + 1;
	
	build(e, ini, m);
	build(d, m+1, fim);
	
	merge(pos);	
}

//----------------------//

void update(int pos, int ini, int fim, int p, int q) {
	//printf("UPDATE: pos = %d, ini = %d, fim = %d, p = %d, q = %d\n", pos, ini, fim, p, q);
	
	if(seg[pos].lz == 1) return;
	
	if(p > fim || q < ini) return;
	if(ini == fim) {
		seg[pos].soma = sqrt(seg[pos].soma);
		if(seg[pos].soma == 1) seg[pos].lz = 1;
		return;
	}
	
	int m = (ini + fim) / 2;
	int e = 2 * pos, d = e + 1;
	
	update(e, ini, m, p, q);
	update(d, m+1, fim, p, q);
	
	merge(pos);
}

long long int query(int pos, int ini, int fim, int p, int q) {
	//printf("QUERY: pos = %d, ini = %d, fim = %d, p = %d, q = %d\n", pos, ini, fim, p, q);

	if(p > fim || q < ini) return 0;
	if(p <= ini && fim <= q) {
		return seg[pos].soma;
	}
	
	int m = (ini + fim) / 2;
	int e = 2 * pos, d = e + 1;
	
	return query(e, ini, m, p, q) + query(d, m+1, fim, p, q);
}

//----------------------//

int main() {
	while(scanf("%d",&n) != EOF) {
		for(int i = 1; i <= n; i++) {
			scanf("%lld",&input[i]);
		}
		build(1,1,n);
		scanf("%d",&q);
		
		printf("Case #%d:\n",casos);
		for(int i = 1; i <= q; i++) {
			int top, ta, tb;
			scanf("%d%d%d",&top,&ta,&tb);
			
			if(ta > tb) {
				swap(ta,tb);
			}
			if(top == 0) update(1, 1, n, ta, tb);
			else printf("%lld\n",query(1, 1, n, ta, tb));
		}
		casos++;
	}
}