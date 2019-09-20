#include <stdio.h>
 
const int MAXN = 1e6;
int n, q;
struct node {
	int i, f, lz, tm0, tm1, tm2;
};
 
struct node seg[MAXN];
 
void build(int pos, int ini, int fim) {
	seg[pos].i = ini;
	seg[pos].f = fim;
	seg[pos].tm0 = (fim - ini + 1);
	seg[pos].tm1 = seg[pos].tm2 = 0;
	
	if(ini == fim) return;
	
	int m = (fim + ini) / 2;
	int e = 2 * pos, d = e + 1;
	
	build(e,ini,m);
	build(d,m+1,fim);
}
 
void refresh(int pos, int ini, int fim) {
	if(seg[pos].lz == 0) return;
	if(seg[pos].lz == 2) {
		int t0 = seg[pos].tm0;
		int t1 = seg[pos].tm1;
		int t2 = seg[pos].tm2;
		
		seg[pos].tm0 = t1;
		seg[pos].tm1 = t2;
		seg[pos].tm2 = t0;
	}
	
	int t0 = seg[pos].tm0;
	int t1 = seg[pos].tm1;
	int t2 = seg[pos].tm2;
	
	seg[pos].tm0 = t1;
	seg[pos].tm1 = t2;
	seg[pos].tm2 = t0;
	
	int e = 2 * pos, d = e + 1;
	
	seg[e].lz += seg[pos].lz;
	seg[d].lz += seg[pos].lz;	
	
	seg[e].lz %= 3;
	seg[d].lz %= 3;
	
	seg[pos].lz = 0;
}
 
void update(int pos, int ini, int fim, int p, int q) {
	// Como o update sempre somara um em cada intervalo, "val" foi omitido e um incremento sera
	// usado em troca.
	refresh(pos, ini, fim);
	
	if(p > fim || q < ini) return;
	else if(p <= ini && q >= fim) {
		seg[pos].lz++; seg[pos].lz %= 3; //printf("seg[pos = %d].lz = %d, RESTO( seg[pos].lz : 3 )= %d\n",pos,seg[pos].lz,seg[pos].lz%3);
		refresh(pos, ini, fim);
		return;
	}
	
	int m = (fim + ini) / 2;
	int e = 2 * pos, d = e + 1;
	
	update(e,ini,  m, p, q);
	update(d,m+1,fim, p, q);
	seg[pos].tm0 = seg[e].tm0 + seg[d].tm0;
	seg[pos].tm1 = seg[e].tm1 + seg[d].tm1;
	seg[pos].tm2 = seg[e].tm2 + seg[d].tm2;
}
 
int query(int pos, int ini, int fim, int p, int q) {
	refresh(pos, ini, fim);
	
	if(p > fim || q < ini) return 0;
	else if(p <= ini && q >= fim) {
		return seg[pos].tm0;
	}
	
	int m = (fim + ini) / 2;
	int e = 2 * pos, d = e + 1;
	
	return query(e,ini,  m, p, q) + query(d,m+1,fim, p, q);
}
 
int main() {
	scanf("%d %d", &n, &q);
	build(1,1,n);
	for(int i = 1; i <= q; i++) {
		int top, ta, tb;
		scanf("%d%d%d", &top, &ta, &tb);
		ta++; tb++;
		if(top == 0) {
			update(1,1,n,ta,tb);
		}
		else {
			printf("%d\n",query(1,1,n,ta,tb));
		}
	}
} 