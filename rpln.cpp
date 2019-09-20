#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAXN = 1e5+10;
const int INF = 2e9;
int n, q, casos;
int seg[4*MAXN];

void update(int pos, int i, int f, int id, int val) {
	//printf("\nUPDATE: pos = %d, i = %d, f = %d, id = %d, val = %d",pos,i,f,id,val);
	if(id < i || id > f) return;
	if(i == f) {
		seg[pos] = val;
		return;
	}
	int m = (f+i) / 2;
	int e = 2 * pos, d = 2 * pos + 1;
	update(e,i,m,id,val);
	update(d,m+1,f,id,val);
	seg[pos] = min(seg[e],seg[d]);
}

int query(int pos, int i, int f, int p, int q) {
	//printf("\nQUERY: pos = %d, i = %d, f = %d, p = %d, q = %d",pos,i,f,p,q);
	if(f < p || i > q) return INF;
	if(i >= p && f <= q) {
		return seg[pos];
	}
	int m = (f+i) / 2;
	int e = 2 * pos, d = 2 * pos + 1;
	return min(query(e,i,m,p,q),query(d,m+1,f,p,q));
}

int main() {
	scanf("%d",&casos);
	for(int z = 0; z < casos; z++) {
		scanf("%d%d",&n,&q);
		for(int i = 1; i <= n; i++) {
			seg[i] = INF;
		}
		for(int i = 1; i <= n; i++) {
			int ta;
			scanf("%d",&ta);
			update(1,1,n,i,ta);
		}
		printf("\nScenario #%d:",z+1);
		for(int i = 1; i <= q; i++) { 
			int ta, tb;
			scanf("%d%d",&ta,&tb);
			printf("\n%d",query(1,1,n,ta,tb));
		}
	}
}
