#include <stdio.h>
#include <vector>
#include <algorithm>

#define debug(args...) fprintf(stderr, args)

using namespace std;

const int MAXN = 5e5, INF = 2e9;
int n, m, d, l;

struct node {
	int val, lz, minimo, qtdMin;
};

struct node seg[4 * MAXN];
vector < int > holes;

//-------------------------------//

void build(int pos, int ini, int fim) {
	if(ini == fim) {
		seg[pos].qtdMin = 1;
		return;
	}

	int m = (ini + fim) / 2;
	int e = 2 * pos, d = e + 1;

	build(e, ini, m);
	build(d, m+1, fim);

	seg[pos].qtdMin = seg[e].qtdMin + seg[d].qtdMin;
}

void refresh(int pos, int ini, int fim) {
	int aux = seg[pos].lz;
	if(seg[pos].lz == 0) return;

	seg[pos].minimo += seg[pos].lz;
	seg[pos].lz = 0;

	if(ini == fim) return;

	int e = 2 * pos, d = e + 1;

	seg[e].lz += aux;
	seg[d].lz += aux;
}

void update(int pos, int ini, int fim, int p, int q, int val) {
	refresh(pos, ini, fim);

	if(fim < p || ini > q) return;
	if(p <= ini && fim <= q) {
		seg[pos].lz += val;
		refresh(pos, ini, fim);
		return;
	}

	int e = 2 * pos, d = e + 1;
	int m = (ini + fim) / 2;

	update(e, ini, m, p, q, val);
	update(d, m+1, fim, p, q, val);

	// Merge
	if(seg[e].minimo == seg[d].minimo)
		seg[pos].qtdMin = seg[e].qtdMin + seg[d].qtdMin;

	if(seg[e].minimo < seg[d].minimo) seg[pos].qtdMin = seg[e].qtdMin;
	else seg[pos].qtdMin = seg[d].qtdMin;

	seg[pos].minimo = min(seg[e].minimo, seg[d].minimo);
}

//-------------------------------//

int main() {
	scanf("%d %d %d %d", &n, &m, &d, &l);
	build(1, 1, n);

	holes.push_back(0);
	for(int i = 2; i <= n; i++) { // Buracos
		int ta;
		scanf("%d", &ta);

		holes.push_back(ta);
	}

	for(int i = 1; i <= m; i++) { // Toca discos
		int ta;
		scanf("%d", &ta);

		int cbeg = lower_bound(holes.begin(), holes.end(), ta - l) - holes.begin();
		// Compressed beginning. Primeiro indice que e atingido pelo
		// toca discos da posicao ta.

		int cfin = upper_bound(holes.begin(), holes.end(), ta + l) - holes.begin() - 1;
		// Compressed final position. Ultimo indice que e atingido pelo
		// toca discos da posicao ta.

		update(1, 1, n, cbeg, cfin, 1);
	}

	for(int i = 0; i < d; i++) {
		int ta, tb;
		scanf("%d %d", &ta, &tb);
		// Tira o toca discos de ta e coloca em tb

		int abeg = lower_bound(holes.begin(), holes.end(), ta - l) - holes.begin();
		// Compressed beginning de ta.
		int afin = upper_bound(holes.begin(), holes.end(), ta + l) - holes.begin() - 1;
		// Compressed final position de ta.

		int bbeg = lower_bound(holes.begin(), holes.end(), tb - l) - holes.begin() + ta;
		// Compressed beginning de tb.
		int bfin = upper_bound(holes.begin(), holes.end(), tb + l) - holes.begin() - 1 + ta;
		// Compressed final position de tb.

		if(seg[1].minimo == 0) printf("%d\n", n - seg[1].qtdMin);
		else printf("%d\n", n);

		update(1, 1, n, abeg, afin, -1);
		update(1, 1, n, bbeg, bfin, 1);
	}
}
