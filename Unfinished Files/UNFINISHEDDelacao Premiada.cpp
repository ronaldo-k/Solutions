#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAXN = 1e5 + 10;
int n, k, mrk[MAXN], dpt[MAXN], prsDpt[MAXN], maxDpt[MAXN], ans;

vector < int > g[MAXN];

void dfs1(int cur) {
	mrk[cur] = 1;

	for(int i = 0; i < g[cur].size(); i++) {
		int ngb = g[cur][i];

		if(mrk[ngb] == 0) {
			prsDpt[ngb] = dpt[ngb] = dpt[cur] + 1;
			dfs1(ngb);
		}
	}

	for(int i = 0; i < g[cur].size(); i++) {
		int ngb = g[cur][i];
		debug("dpt[ngb = %d] = %d", ngb, dpt[ngb]);
		dpt[cur] = max(dpt[ngb], dpt[cur]);
	}
}

void dfs2(int cur, int d) {
	//debug("-> %d %d\n", cur, d);

	int maxDist, id;
	maxDist = id = 0;
	mrk[cur] = 2;

	for(int i = 0; i < g[cur].size(); i++) {
		int ngb = g[cur][i];
		//debug("ngb = %d\n", ngb);

		if(mrk[ngb] == 1 && maxDist <= dpt[ngb]) {
			maxDist = dpt[ngb];
			id = ngb;
		}
	}

	if(id != 0) {
		maxDpt[id] = dpt[id];

		dfs2(id, d+1);
	}

	for(int i = 0; i < g[cur].size(); i++) {
		int ngb = g[cur][i];
		//debug("ngb = %d\n", ngb);

		if(mrk[ngb] == 1 && ngb != id) {
			maxDpt[ngb] = max(maxDpt[ngb], d);

			dfs2(id, 0);
		}
	}
}

int main() {
	scanf("%d %d", &n, &k);

	for(int i = 2; i <= n; i++) {
		int ta;
		scanf("%d", &ta);

		g[ta].push_back(i);
	}

	dfs1(1);

	debug("\ndpt:\n");
	for(int i = 1; i <= n; i++) {
		debug("%d -> %d\n", i, dpt[i]);
	}

	dfs2(1, 0);

	debug("maxDpt:\n");
	for(int i = 1; i <= n; i++) {
		debug("%d -> %d\n", i, maxDpt[i]);
	}

	sort(maxDpt + 1, maxDpt + n+1);

	for(int i = n; i >= n-k+1; i--) {
		ans += maxDpt[i];
	}

	printf("%d\n", ans);
}
