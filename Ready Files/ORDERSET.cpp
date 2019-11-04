// BINARY SEARCH IN SEGMENT TREE — ORDERSET (Insert source)

#include <stdio.h>
#include <vector>

#define debug(args...) fprintf(stderr, args)

using namespace std;

const int INF = 1e9;
int q;
vector < int > sum, e, d;

int create() {
	sum.push_back(0);
	e.push_back(-1);
	d.push_back(-1);
	return sum.size() - 1;
}

void update(int pos, int ini, int fim, int id, int val) {
	if(id < ini || id > fim) return;
	if(ini == fim) {
		sum[pos] = val; return;
	}

	int m = (ini + fim) / 2;
	if(ini == fim - 1) m = ini;

	if(id <= m) {
		if(e[pos] == -1) {
			int aux = create(); e[pos] = aux;
		}
		update(e[pos], ini, m, id, val);
	}
	else {
		if(d[pos] == -1) {
			int aux = create(); d[pos] = aux;
		}
		update(d[pos], m+1, fim, id, val);
	}

	if(e[pos] == -1) sum[pos] = sum[d[pos]];
	else if(d[pos] == -1) sum[pos] = sum[e[pos]];
	else sum[pos] = sum[e[pos]] + sum[d[pos]];
}

int query(int pos, int ini, int fim, int q) {
	if(pos == -1 || q < ini) return 0;
	if(fim <= q) {
		return sum[pos];
	}

	int m = (ini + fim) / 2;
	if(ini == fim - 1) m = ini;

	return query(d[pos], m+1, fim, q) + query(e[pos], ini, m, q);
}

int binarySearch(int pos, int ini, int fim, int v) {
	if(ini == fim) return ini;

	int se = (e[pos] == -1) ? 0 : sum[e[pos]];
	int m = (ini + fim) / 2;
	if(ini == fim - 1) m = ini;

	if(se >= v) {
		return binarySearch(e[pos], ini, m, v);
	}
	else {
		return binarySearch(d[pos], m+1, fim, v - se);
	}
}

int main() {
	create(); create();
	scanf("%d", &q);
	for(int i = 0; i < q; i++) {
		char top; int ta;
		scanf(" %c %d", &top, &ta);

		if(top == 'I') {
			update(1, -INF, INF, ta, 1);
		}
		if(top == 'D') {
			update(1, -INF, INF, ta, 0);
		}
		if(top == 'K') {
			if(sum[1] < ta) printf("invalid\n");
			else printf("%d\n", binarySearch(1, -INF, INF, ta));
		}
		if(top == 'C') {
			printf("%d\n", query(1, -INF, INF, ta-1));
		}
	}
}
