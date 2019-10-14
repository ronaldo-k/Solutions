// DFS – Imposto Real (URI Maratona de Programção da SBC-ACM ICPC 2017)

#include <stdio.h>
#include <vector>

using namespace std;

#define debug(args...) //fprintf(stderr, args);

const int MAXN = 1e4 + 10;

int n, c, v[MAXN], mrk[MAXN], sub[MAXN], subAmt[MAXN];

vector < int > g[MAXN], w[MAXN];

int ceiling(int a, int b) {
	// Ceiling of a/b
	return (a+b-1)/b;
}

void dfs(int cur) {
	int tamt = 0, tsub = 0;
	mrk[cur] = 1;
	sub[cur] = v[cur];

	for(int i = 0; i < g[cur].size(); i++) {
		int ngb = g[cur][i], nw = w[cur][i];

		if(mrk[ngb] == 0) {
			dfs(ngb);
			sub[cur] += sub[ngb];
			tamt += subAmt[ngb];
			tsub += 2*nw*ceiling(sub[ngb],c);
		}
	}
	subAmt[cur] = tsub + tamt;
}

int main() {
	scanf("%d %d", &n, &c);

	for(int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}

	for(int i = 1; i <= n-1; i++) {
		int ta, tb, tw;
		scanf("%d %d %d", &ta, &tb, &tw);
		g[ta].push_back(tb); g[tb].push_back(ta);
		w[ta].push_back(tw); w[tb].push_back(tw);
	}

	dfs(1);

	printf("%d\n", subAmt[1]);
}
