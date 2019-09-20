#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAXN = 5e4 + 10, MAXL = 20;

int n, fat[MAXN], dep[MAXN], mrk[MAXN], dp[MAXN][MAXL], ans;
vector < int > g[MAXN];
vector < pair < int, int > > in;

void solve() {
	for(int i = 1; i <= n; i++) {
		dp[i][0] = fat[i];
	}

	for(int g = 1; g < MAXL; g++) {
		for(int i = 1; i <= n; i++) {
			dp[i][g] = dp[ dp[i][g-1] ][g-1];
		}
	}
}

void dfs(int v) {
	mrk[v] = 1;

	for(int i = 0; i < g[v].size(); i++) {
		int ngb = g[v][i];

		if(mrk[ngb] == 0) {
			fat[ngb] = v;
			dep[ngb] = dep[v] + 1;

			dfs(ngb);
		}
	}
}

int lca(int a, int b) {
	debug("LCA: %d %d\n", a, b);

	if(a == b) return a;

	if(dep[a] > dep[b]) {
		int aux = a; a = b; b = aux;
	}

	if(dep[a] < dep[b]) {
		int dist = dep[b] - dep[a];

		for(int i = 0; i <= MAXL; i++) {
			if(dist & (1<<i)) b = dp[b][i];
		}
	}

	if(dep[a] == dep[b]) {
		for(int i = MAXL-1; i >= 0; i--) {
			if(dp[a][i] != dp[b][i]) {
				a = dp[a][i];
				b = dp[b][i];
			}
		}
	}

	return fat[b];
}

int main() {
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) {
		int ta;
		scanf("%d", &ta);

		in.resize(n/2);

		if(in[ta].first == 0) in[ta] = make_pair(i, 0);
		else in[ta] = make_pair(in[ta].first, i);
	}

	for(int i = 1; i <= n-1; i++) {
		int ta, tb;
		scanf("%d %d", &ta, &tb);

		g[ta].push_back(tb);
		g[tb].push_back(ta);
	}

	dfs(1); // Using DFS to compute fat[] and dep[]
	solve();

	for(int i = 0; i < in.size(); i++) {
		int d = dep[lca(in[i].first, in[i].second)], a = dep[in[i].first], b = dep[in[i].second];
		ans += a + b - d;
		debug("ans[%d] (%d, %d): %d\n", i, in[i].first, in[i].second, ans);
	}
}
