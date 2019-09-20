#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1e5;
const int INF = 1e9;

struct node {
	int max1, max2;
};

int n, q;
struct node seg[4 * MAXN];

struct node merge(struct node a, struct node b) {
	struct node aux;
	/*vector <int> z;
	z.push_back(a.max1); z.push_back(b.max1);
	z.push_back(a.max2); z.push_back(b.max2);
	
	sort(z.begin(), z.end());
	
	aux.max1 = z[3];
	aux.max2 = z[2];*/
	//printf("merge dentro sai max1=%d max2=%d\n", aux.max1, aux.max2);
	aux.max1=max(a.max1, b.max1);
	aux.max2 = (aux.max1 == a.max1) ? (max(a.max2, b.max1)) : (max(a.max1, b.max2));
	return aux;
}

void update(int pos, int ini, int fim, int id, int val) {
	//printf("UPDATE: pos = %d, ini = %d, fim = %d, id = %d, val = %d\n",pos,ini,fim,id,val);
	if(id > fim || id < ini) return;
	if(ini == fim) {
		//printf("update dentro: pos=%d val=%d\n", pos, val);
		seg[pos].max1 = val;
		seg[pos].max2 = -INF;
		return;
	}
	
	int m = (ini + fim) / 2;
	int e = 2 * pos, d = e + 1;
	
	update(e, ini, m, id, val);
	update(d, m+1, fim, id, val);
	
	seg[pos] = merge(seg[e],seg[d]);
}

struct node query(int pos, int ini, int fim, int p, int q) {
	if(p > fim || q < ini) {
		struct node a;
		a.max1 = a.max2 = -INF;
		return a;
	}
	//if(p <= fim && q >= ini) {
	if(ini >= p && fim <= q) {
		//printf("query dentro: pos=%d max1=%d max2=%d\n", pos, seg[pos].max1, seg[pos].max2);
		return seg[pos];
	}
	
	int m = (ini + fim) / 2;
	int e = 2 * pos, d = e + 1;
	
	struct node qe = query(e, ini, m, p, q);
	struct node qd = query(d, m+1, fim, p, q);
	
	return merge(qe, qd);
}

int main() {
	scanf("%d",&n);
	for(int i = 1; i <= n; i++) {
		int ta;
		scanf("%d",&ta);
		update(1, 1, n, i, ta);
	}
	scanf("%d",&q);
	for(int i = 1; i <= q; i++) {
		int ta, tb;
		char top;
		scanf(" %c%d%d",&top,&ta,&tb);
		if(top == 'U') {
			update(1, 1, n, ta, tb);
		}
		else {
			struct node aux = query(1, 1, n, ta, tb);
			printf("%d\n",aux.max1 + aux.max2);
		}
	} 
}