#include <stdio.h>

const int MAXN = 1e6;
const long long int INF = 9e18;
int casos, n, q;

struct node {
	int i, f;
	long long int v,lz;
};

struct node seg[4*MAXN];

void build(long long int pos, int ini, int fim) {
	seg[pos].i = ini;
	seg[pos].f = fim;
	seg[pos].lz = seg[pos].v = 0;
	
	if(ini == fim) return;
	
	long long int m = (fim + ini) / 2, e = 2 * pos, d = e + 1;
	
	build(e, ini, m);
	build(d, m+1, fim);
}

void refresh(long long int pos, int ini, int fim) {
	//printf("REFRESH: pos = %lld, ini = %d, fim = %d, seg[pos].lz = %lld\n",pos,ini,fim,seg[pos].lz);
	if(seg[pos].lz == 0) return;
	seg[pos].v += seg[pos].lz * (fim - ini + 1);
	
	long long int e = 2 * pos, d = e + 1;
	
	seg[e].lz += seg[pos].lz;
	seg[d].lz += seg[pos].lz;
	
	seg[pos].lz = 0;
}

long long int query(long long int pos, int ini, int fim, int p, int q) {
	refresh(pos, ini, fim);
	
	//printf("QUERY: pos = %lld, ini = %d, fim = %d, p = %d, q = %d, up = %lld\n",pos,ini,fim,p,q,seg[pos].v);
	
	if(p > fim || q < ini) return 0;
	else if(p <= ini && q >= fim) {
		return seg[pos].v;
	}
	
	long long int m = (fim + ini) / 2, e = 2 * pos, d = e + 1;
	
	return query(e, ini, m, p, q) + query(d, m+1, fim, p, q);
}

void update(long long int pos, int ini, int fim, int p, int q, int val) {
	refresh(pos, ini, fim);
	if(p > fim || q < ini) return;
	else if(p <= ini && q >= fim) {
		seg[pos].lz += val;
		refresh(pos, ini, fim);
		return;
	}
	
	long long int m = (fim + ini) / 2, e = 2 * pos, d = e + 1;
	
	update(e, ini, m, p, q, val);
	update(d, m+1, fim, p, q, val);
	
	seg[pos].v = seg[e].v + seg[d].v;
}

int main() {
	scanf("%d",&casos);
	for(int z = 1; z <= casos; z++) {
		scanf("%d %d", &n, &q);
		build(1,1,n);
		for(int i = 1; i <= q; i++) {
			int top, ta, tb, tv;
			scanf("%d", &top);
			if(top == 0) {
				scanf("%d %d %d", &ta, &tb, &tv); // Update
				update(1, 1, n, ta, tb, tv);
			}
			else {
				scanf("%d %d", &ta, &tb); // Query
				printf("%lld\n",query(1, 1, n, ta, tb));
			}
		}
	}
}