#include <stdio.h>
#include <vector>

using namespace std;

const int MAXN = 2e5 + 10;

struct query {
	int u, l, r;
};

struct node {
	int v, id, lz;

	node(int vIn = INF, int idIn = -1, int lzIn = 0) {
		v = vIn;
		id = idIn;
		lz = lzIn;
	}
};

int n, m, seg[4*MAXN];

vector < struct query > q;

void updateSeg(int pos, int ini, int fim, int p, int q) {
	refresh(pos, ini, fim);

	if(p > fim || ini < q) return;
	if(p <= ini && fim <= q) {
		seg[pos].lz++;
		refresh(pos, ini, fim);
		return;
	}

	int m = (ini + fim) / 2, e = 2 * pos, d = e + 1;

	updateSeg(e, ini, m, p, q); updateSeg(d, m+1, fim, p, q);

	if(seg[e].v < seg[d].v) {
		seg[pos].v = seg[e].v;
		seg[pos].id = seg[e].id;
	}
	else {
		seg[pos].v = seg[d].v;
		seg[pos].id = seg[d].id;
	}
}

struct node querySeg(int pos, int ini, int fim, int p, int q) {
	refresh(pos, ini, fim);

	if(p > fim || ini < q) return;
	if(p <= ini && fim <= q) {
		return seg[pos].id;
	}

	int m = (ini + fim) / 2, e = 2 * pos, d = e + 1;

	struct node l = querySeg(e, ini, m, p, q);
	struct node r = querySeg(d, m+1, fim, p, q);

	if(l.v < r.v) {
		return
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= m; i++) {
		struct query t;
		scanf("%d %d %d", &t.u, &t.l, &t.r);
		q.push_back(t);
	}
}
