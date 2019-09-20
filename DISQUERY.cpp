// REVIEW: LCA – DISQUERY (SPOJ)
// 09/09/2019

#include <stdio.h>
#include <vector>

using namespace std;

#define debug(args...) //fprintf(stderr, args)

const int MAXN = 1e5, MAXL = 20, INF = 2e9;
int n, m, dpAnc[MAXN][MAXL], dpMax[MAXN][MAXL], dpMin[MAXN][MAXL], mrk[MAXN], fat[MAXN], dpt[MAXN], ansMax, ansMin;
vector < int > g[MAXN], w[MAXN];

void dfs(int cur) {
	mrk[cur] = 1;

	for(int i = 0; i < g[cur].size(); i++) {
		int ngb = g[cur][i], p = w[cur][i];

		if(mrk[ngb] == 0) {
			fat[ngb] = dpAnc[ngb][0] = cur;
			dpt[ngb] = dpt[cur] + 1;

			dpMin[ngb][0] = dpMax[ngb][0] = p;

			dfs(ngb);
		}
	}
}

void solve() {
	for(int i = 1; i < MAXL; i++) {
		for(int j = 1; j <= n; j++) {
			dpAnc[j][i] = dpAnc[ dpAnc[j][i-1] ][i-1];
			dpMax[j][i] = max(dpMax[ dpAnc[j][i-1] ][i-1], dpMax[j][i-1]);
			dpMin[j][i] = min(dpMin[ dpAnc[j][i-1] ][i-1], dpMin[j][i-1]);

			debug("dpAnc[%d][%d] = %d\n", j, i, dpAnc[j][i]);
			debug("dpMax[%d][%d] = %d\n", j, i, dpMax[j][i]);
			debug("dpMin[%d][%d] = %d\n\n", j, i, dpMin[j][i]);
		}
	}
}

void lca(int a, int b) {
	if(dpt[a] > dpt[b]) swap(a, b);

	if(dpt[a] < dpt[b]) {
		int d = dpt[b] - dpt[a];

		for(int i = 0; i < MAXL; i++) {
			int curBit = d & (1<<i);

			if(curBit) {
				ansMax = max(dpMax[b][i], ansMax);
				ansMin = min(dpMin[b][i], ansMin);
				b = dpAnc[b][i];
			}
		}
	}

	debug("dpta = %d, dptb = %d, a = %d, b = %d\n",dpt[a], dpt[b], a, b);

	if(a == b) return;

	for(int i = MAXL-1; i >= 0; i--) {
		if(dpAnc[b][i] != dpAnc[a][i]) {
			ansMax = max( max(dpMax[a][i], dpMax[b][i]), ansMax );
			ansMin = min( min(dpMin[a][i], dpMin[b][i]), ansMin );

			b = dpAnc[b][i]; a = dpAnc[a][i];
		}
	}

	ansMax = max( max(dpMax[a][0], dpMax[b][0]), ansMax );
	ansMin = min( min(dpMin[a][0], dpMin[b][0]), ansMin );
}

int main() {
	scanf("%d", &n);

	for(int i = 0; i < n-1; i++) {
		int ta, tb, tw;
		scanf("%d %d %d", &ta, &tb, &tw);
		g[ta].push_back(tb); g[tb].push_back(ta);
		w[ta].push_back(tw); w[tb].push_back(tw);
	}

	fat[1] = dpAnc[1][0] = 1;
	dpMax[1][0] = -INF; dpMin[1][0] = INF;
	dfs(1);
	solve();

	scanf("%d", &m);

	for(int i = 0; i < m; i++) {
		ansMax = -INF; ansMin = INF;
		int ta, tb;
		scanf("%d %d", &ta, &tb);

		lca(ta, tb);

		printf("%d %d\n", ansMin, ansMax);
	}
}
