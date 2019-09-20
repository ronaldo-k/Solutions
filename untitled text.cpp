#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAXN = 5e5;
const int INF = 2e9;

int n, m;

struct node {
	int ini, fim, s, se, sd, soma;
};

struct node seg[MAXN], resp;

struct node merge(int pos, int e, int d, struct node aux) {
	aux.s = max(aux.s, aux.s, aux.sd + aux.se);
	aux.soma = aux.e + aux.d;
	
	aux.se = max(aux.se, aux.soma + aux.se);
	aux.sd = max(aux.sd, aux.soma + aux.sd);
	
	return struct node aux; 
}

struct node clear(struct node a) {
	a.se = a.sd = a.s = -INF;
	a.soma = 0;
	
	return struct node a;
}

void build(int pos, int ini, int fim, int val) {
	if(ini == fim) {
		seg[pos].s = seg[pos].soma = seg[pos].sd = seg[pos].se = val;
		return;
	}
	int m = (ini + fim) / 2;
	int e = 2 * pos, d = e + 1;
	
	build(e, ini, m);
	build(d, m+1, fim);
	seg[pos] = merge(e,d);
}

int query(int pos, int ini, int fim, int p, int q) {
	resp = clear(seg[pos]);
	if(fim < p || ini > q) return INF;
	if(fim >= p && ini <= q) {
		return seg[pos].s;
	}
	
	int m = (ini + fim) / 2;
	int e = 2 * pos, d = e + 1;
	
	build(e, ini, m, p, q);
	build(d, m+1, fim, p, q);
	return seg[pos].s;
}

int main() {
	scanf("%d",&n);
	for(int i = 1; i <= n; i++) {
		int ta;
		scanf("%d",&ta);
		build(1,n,i,ta);
	}
	scanf("%d",&m);
	for(int i = 1; i <= m; i++) {
		int ta, tb;
		scanf("%d%d",&ta,&tb);
		printf("\n%d",query(1,1,n,ta,tb));
	}
}