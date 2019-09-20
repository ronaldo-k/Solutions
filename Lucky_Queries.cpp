#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAXN = 1e6+10;
int n, q;
char input[MAXN], inq[20];

struct node {
	int t4, t7, t47, t74, lz;
};

struct node seg[4 * MAXN];

void merge(int pos) {
	//printf("MERGE: pos = %d\n", pos);
	int e = 2 * pos, d = e + 1;
	
	seg[pos].t47 = 0;
	seg[pos].t47 = max(seg[pos].t47, seg[e].t4 + seg[d].t47);
	seg[pos].t47 = max(seg[pos].t47, seg[e].t47 + seg[d].t7);
	seg[pos].t47 = max(seg[pos].t47, seg[e].t4 + seg[d].t7);
	
	seg[pos].t74 = 0;
	seg[pos].t74 = max(seg[pos].t74, seg[e].t7 + seg[d].t74);
	seg[pos].t74 = max(seg[pos].t74, seg[e].t74 + seg[d].t4);
	seg[pos].t74 = max(seg[pos].t74, seg[e].t7 + seg[d].t4);
	
	seg[pos].t4 = seg[e].t4 + seg[d].t4;
	seg[pos].t7 = seg[e].t7 + seg[d].t7;
	
	seg[pos].t47 = max(seg[pos].t47, max(seg[pos].t4, seg[pos].t7));
	seg[pos].t74 = max(seg[pos].t74, max(seg[pos].t4, seg[pos].t7));
}

void build(int pos, int ini, int fim) {
	//printf("BUILD: pos = %d, ini = %d, fim = %d\n", pos, ini, fim);
	if(ini == fim) {
		if(input[ini] == '4') {
			seg[pos].t4 = seg[pos].t47 = seg[pos].t74 = 1;
			seg[pos].t7 = 0;
		}
		else {
			seg[pos].t7 = seg[pos].t47 = seg[pos].t74 = 1;
			seg[pos].t4 = 0;
		}
		return;
	}
	
	int m = (ini + fim) / 2;
	int e = 2 * pos, d = e + 1;
	
	build(e, ini, m);
	build(d, m+1, fim);
	
	merge(pos);
	//printf("BUILD -> Na seg[pos = %d]: t4 = %d, t7 = %d, t47 = %d, t74 = %d\n", pos, seg[pos].t4, seg[pos].t7, seg[pos].t47, seg[pos].t74);

	seg[pos].lz = 0;
}

void refresh(int pos, int ini, int fim) {
	//printf("REFRESH: pos = %d, ini = %d, fim = %d\n", pos, ini, fim);
	if(seg[pos].lz == 0) return;
	
	int temp7 = seg[pos].t7;
	int temp4 = seg[pos].t4;
	int temp47 = seg[pos].t47;
	int temp74 = seg[pos].t74;
	
	seg[pos].t7 = temp4;
	seg[pos].t4 = temp7;
	seg[pos].t47 = temp74;
	seg[pos].t74 = temp47;
	
	seg[pos].lz = 0;
	
	//printf("REFRESH -> Na seg[pos = %d]: t4 = %d, t7 = %d, t47 = %d, t74 = %d\n", pos, seg[pos].t4, seg[pos].t7, seg[pos].t47, seg[pos].t74);
	
	if(ini == fim) return;
	
	int e = 2 * pos, d = e + 1;
	
	seg[e].lz ^= 1;
	seg[d].lz ^= 1;
}

//------------------------//

void update(int pos, int ini, int fim, int p, int q) {
	refresh(pos, ini, fim);
	//printf("UPDATE: pos = %d, ini = %d, fim = %d, p = %d, q = %d\n", pos, ini, fim, p, q);
	if(p > fim || q < ini) return;
	if(q >= fim && p <= ini) {
		seg[pos].lz = 1;
		refresh(pos, ini, fim);
		return;
	}
	
	int m = (ini + fim) / 2;
	int e = 2 * pos, d = e + 1;
	
	update(e, ini, m, p, q);
	update(d, m+1, fim, p, q);
	
	merge(pos);
}

//------------------------//

int main() {
	scanf("%d%d",&n,&q);
	
	scanf(" %s", input);
	//printf("input = %s\n", input);
	
	build(1, 0, n-1);
	
	for(int i = 1; i <= q; i++) {
		scanf(" %s", inq);
		//printf("inq = %s", inq);
			
		if(inq[0] == 's') {
			int ta, tb;
			
			scanf("%d%d",&ta,&tb); ta--; tb--;
			
			update(1, 0, n-1, ta, tb);
		}
		else {
			printf("%d\n",seg[1].t47);
		}
	}
}