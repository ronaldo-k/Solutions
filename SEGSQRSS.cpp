#include <stdio.h>

const int MAXN = 4e5 + 10; // 4 * 10^5
int casos, n, q;

struct node {
	long long int sqSum, lzSum, lzSet, sum;
	
	// sqSum: Guarda as somas dos quadrados
	// lzSum: Lazy Propagation da soma
	// lzSet: Lazy Propagation do set
	// sum: Guarda a soma do intervalo
};

struct node seg[4 * MAXN];

//---------------------------//

void refreshSet(int pos, int ini, int fim) {
	if(seg[pos].lzSet == 1001) return;
	
	int k = fim - ini + 1;
	int e = 2 * pos, d = e + 1;
	
	seg[pos].sum = (k * seg[pos].lzSet);
	seg[pos].sqSum = k * (seg[pos].lzSet * seg[pos].lzSet);
	
	if(ini == fim) { 
		seg[pos].lzSet = 1001;
		return;
	}
	
	seg[e].lzSet = seg[d].lzSet = seg[pos].lzSet;
	seg[e].lzSum = seg[d].lzSum = 0;
	
	seg[pos].lzSet = 1001;
}

void refreshSum(int pos, int ini, int fim) {
	if(seg[pos].lzSum == 0) return;
	//printf("refreshSum pos=%d ini=%d fim=%d\n", pos, ini, fim);
	int k = fim - ini + 1;
	int e = 2 * pos, d = e + 1;
	
	seg[pos].sqSum = (k * (seg[pos].lzSum * seg[pos].lzSum)) + seg[pos].sqSum + (2 * seg[pos].lzSum * seg[pos].sum);
	seg[pos].sum = seg[pos].sum + (k * seg[pos].lzSum);
		
	if(ini == fim) {
		seg[pos].lzSum = 0;
		return;
	}
	seg[e].lzSum += seg[pos].lzSum;
	seg[d].lzSum += seg[pos].lzSum;
	
	seg[pos].lzSum = 0;
}

void refresh(int pos, int ini, int fim) {
	refreshSet(pos, ini, fim);
	refreshSum(pos, ini, fim);
}

//---------------------------//

void update(int pos, int ini, int fim, int p, int q, int val, int tipo) {
	refresh(pos, ini, fim);
	if(p > fim || q < ini) return;
	
	int m = (ini + fim) / 2;
	int e = 2 * pos, d = e + 1;
	
	if(p <= ini && fim <= q) {
		if(tipo == 0) {
			seg[pos].lzSet = val;
			seg[pos].lzSum = 0;
			
		}
		else {
			seg[pos].lzSum += val;
		}
		refresh(pos, ini, fim);
		//printf("dentro update pos=%d ini=%d fim=%d sum=%d sqsum=%d\n", pos, ini, fim, seg[pos].sum, seg[pos].sqSum);
		return;
	}
	update(e, ini, m, p, q, val, tipo);
	update(d, m+1, fim, p, q, val, tipo);
	
	seg[pos].sum = seg[e].sum + seg[d].sum;
	seg[pos].sqSum = seg[e].sqSum + seg[d].sqSum;
	//printf("update pos=%d ini=%d fim=%d sum=%d sqsum=%d\n", pos, ini, fim, seg[pos].sum, seg[pos].sqSum);
}

long long int query(int pos, int ini, int fim, int p, int q) {
	refresh(pos, ini, fim);
	
	if(p > fim || q < ini) return 0;
	if(p <= ini && fim <= q) {
		//refresh(pos, ini, fim);
		return seg[pos].sqSum;
	}
	
	int m = (ini + fim) / 2;
	int e = 2 * pos, d = e + 1;

	return query(e, ini, m, p, q) + query(d, m+1, fim, p, q);
}

//---------------------------//

int main() {
	scanf("%d",&casos);
	for(int test = 1; test <= casos; test++) {
		scanf("%d%d",&n,&q);
		for(int i = 0; i < 4 * MAXN; i++) {
			seg[i].sqSum = seg[i].lzSum = seg[i].sum = 0;
			seg[i].lzSet = 1001;
		}
		
		for(int i = 1; i <= n; i++) {
			int ta;
			scanf("%d",&ta);
			update(1, 1, n, i, i, ta, 0);
		}
		
		printf("Case %d:\n", test);
		for(int i = 0; i < q; i++) {
			int top, ta, tb, tc; // Para a entrada
			
			scanf("%d%d%d",&top,&ta,&tb);
			
			if(top == 2) {
				printf("%lld\n",query(1, 1, n, ta, tb));
			}
			else if(top == 1) { // Update para soma
				scanf("%d",&tc);
				update(1, 1, n, ta, tb, tc, 1);
			}
			else {
				scanf("%d",&tc);
				update(1, 1, n, ta, tb, tc, 0);
			}
		}
	}
}