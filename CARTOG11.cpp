// TREE DIAMETER — CARTOG11 (SPOJ)
// Made on: 20/05/2019

#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAXN = 2e6;
int n, md, ans, dst[MAXN], mrk[MAXN];
vector < int > g[MAXN];

void dfs(int cur) {
	mrk[cur] = 1;

	for(int i = 0; i < g[cur].size(); i++) {
		int ngb = g[cur][i];

		if(mrk[ngb] != 1) {
			dst[ngb] = dst[cur] + 1;
			mrk[ngb] = 1;

			dfs(ngb);
		}
	}
}

int main() {
	scanf("%d", &n);

	for(int i = 1; i <= n-1; i++) {
		int ta, tb;

		scanf("%d %d", &ta, &tb);
		g[ta].push_back(tb);
		g[tb].push_back(ta);
	}

	dfs(1);

	for(int i = 1; i <= n; i++) {
		if(dst[i] > dst[md]) md = i;
	}

	memset(dst, 0, sizeof(dst));
	memset(mrk, 0, sizeof(mrk));

	dfs(md);

	for(int i = 1; i <= n; i++) {
		ans = max(ans, dst[i]);
	}

	printf("%d\n", ans);
}
