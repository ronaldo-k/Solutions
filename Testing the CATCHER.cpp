// LIS (Segment Tree) – Testing the CATCHER (UVa 213)
// Made on: 10/06/2019

#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

const int MAXN = 2e5 + 10, MAXC = 32770;

int v[MAXN], seg[4 * MAXC];

void update(int pos, int ini, int fim, int id, int val) {
	if(id < ini || id > fim) return;
	if(ini == fim) {
		seg[pos] = max(seg[pos], val);
		return;
	}

	int m = (ini + fim) / 2;
	int e = 2 * pos, d = e + 1;

	update(e, ini, m, id, val);
	update(d, m+1, fim, id, val);

	seg[pos] = max(seg[e], seg[d]);
}

int query(int pos, int ini, int fim, int p, int q) {
	if(p > fim || q < ini) return 0;
	if(p <= ini && fim <= q) return seg[pos];

	int m = (ini + fim) / 2;
	int e = 2 * pos, d = e + 1;

	return max(query(e, ini, m, p, q), query(d, m+1, fim, p, q));
}

int main() {
	int test = 1;
	while(true) {
		int aux2, n = 1;
		memset(v, 0, sizeof(v));
		memset(seg, 0, sizeof(seg));

		scanf("%d", &aux2);
		if(aux2 == -1) return 0;
		else v[0] = aux2 + 1;

		while(true) {
			int aux;
			scanf("%d", &aux);
			if(aux != -1) {
				v[n] = aux + 1;
				n++;
			}
			else break;
		}

		for(int i = 0; i < n; i++) {
			update(1, 1, MAXC, v[i], query(1, 1, MAXC, v[i], MAXC) + 1);
		}

		if(test > 1) printf("\n");
		printf("Test #%d:\n  maximum possible interceptions: %d\n", test, query(1, 1, MAXC, 1, MAXC));
		test++;
	}
}
