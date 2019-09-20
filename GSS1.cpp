#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAXN = 5e5 + 10;
const int INF = 2e9;

int n, m;
int v[MAXN];
struct node {
	int s, se, sd, soma;
};

struct node seg[4 * MAXN], resp;

struct node merge(struct node a, struct node b) {
	//printf("MERGE\n");
	struct node aux;
	aux.soma = a.soma + b.soma;
	
	aux.s = max(max(a.s, b.s), a.sd + b.se);
	aux.se = max(a.se, a.soma + b.se);
	aux.sd = max(b.sd, b.soma + a.sd);
	return aux;
}

void clearresp() {
	//printf("CLEAR\n");
	resp.se = resp.sd = resp.s = -INF;
	resp.soma = 0;
}

void build(int pos, int ini, int fim) {
	//printf("BUILD: pos = %d, ini = %d, fim = %d\n",pos,ini,fim);
	if(ini == fim) {
		seg[pos].s = seg[pos].soma = seg[pos].sd = seg[pos].se = v[ini];
		return;
	}
	int m = (ini + fim) / 2;
	int e = 2 * pos, d = e + 1;
	
	build(e, ini, m);
	build(d, m+1, fim);
	
	seg[pos] = merge(seg[e],seg[d]);
}

void query(int pos, int ini, int fim, int p, int q) {
	//printf("QUERY: pos = %d, ini = %d, fim = %d, p = %d, q = %d\n",pos,ini,fim,p,q);
	if(fim < p || ini > q) return;
	if(ini >= p && fim <= q) {
		resp = merge(resp,seg[pos]);
		return;
	}
	
	int m = (ini + fim) / 2;
	int e = 2 * pos, d = e + 1;
	
	query(e, ini, m, p, q);
	query(d, m+1, fim, p, q);
}

int main() {
	scanf("%d",&n);
	for(int i = 1; i <= n; i++) {
		scanf("%d",&v[i]);
	}
	build(1,1,n);
	scanf("%d",&m);
	for(int i = 1; i <= m; i++) {
		int ta, tb;
		scanf("%d%d",&ta,&tb);
		clearresp();
		query(1,1,n,ta,tb);
		printf("%d\n",resp.s);
	}
}