// MULTIPLE BFSs [ About O(n²) ]– Book Of Evil (Codeforces)
// This code will only work in cases 1 through 5, exceeding the problem's time
// limit in case 6.

#include <stdio.h>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define debug(args...) //fprintf(stderr, args);

const int MAXN = 1e5 + 10, INF = 2e9;

int n, m, d, ans, beg[MAXN], dst[MAXN], cnt[MAXN], vst[MAXN];

vector < int > g[MAXN];
queue < int > q;
set < int > inis;

void printStats() {
	debug("Distances:\n");
	for(int i = 1; i <= n; i++) {
		debug("dst[%d] = %d\n", i, dst[i]);
	}

	debug("Counts:\n");
	for(int i = 1; i <= n; i++) {
		debug("cnt[%d] = %d\n", i, cnt[i]);
	}

	debug("Visits:\n");
	for(int i = 1; i <= n; i++) {
		debug("vst[%d] = %d\n", i, vst[i]);
	}
	debug("\n");
}

void BFS(int beg) {
	for(int i = 1; i <= n; i++) {
		dst[i] = INF;
	}
	dst[beg] = 0;
	q.push(beg);

	while(!q.empty()){
		int cur = q.front(); q.pop();
		vst[cur]++;

		if(dst[cur] <= d) {
			debug("%d=> +1\n", cur);
			cnt[cur]++;
		}

		for(int i = 0; i < g[cur].size(); i++) {
			int ngb = g[cur][i];
			//debug("%d --> %d\n", cur, ngb);

			if(dst[ngb] > dst[cur] + 1) {
				dst[ngb] = dst[cur] + 1;
				q.push(ngb);
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &d);

	for(int i = 0; i < m; i++) {
		scanf("%d", &beg[i]);
	}

	for(int i = 0; i < n-1; i++) {
		int ta, tb;
		scanf("%d %d", &ta, &tb);
		g[ta].push_back(tb);
		g[tb].push_back(ta);
	}

	for(int i = 0; i < n; i++) {
		BFS(beg[i]);
	}
	//printStats();

	for(int i = 1; i <= n; i++) {
		if(cnt[i] >= m) ans++;
	}

	printf("%d\n", ans);
}
