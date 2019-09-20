// DIJKSTRA — PONTES09 (SPOJ)
// Made on: 20/05/2019

#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 2000, INF = 2e9;

int n, m, dst[MAXN], mrk[MAXN];
vector < int > g[MAXN], w[MAXN];

void dijkstra(int v) {
	set < pair < int, int > > q;

	for(int i = 0; i <= n+1; i++) {
		dst[i] = INF; mrk[i] = 0;
		q.insert( make_pair(INF, i) );
	}
	dst[v] = 0; mrk[v] = 1;

	q.insert( make_pair(0, v) );

	while(!q.empty()) {
		int cur = q.begin() -> second;
		q.erase(q.begin());
		mrk[cur] = 1;

		for(int i = 0; i < g[cur].size(); i++) {
			int ngb = g[cur][i], nw = w[cur][i];

			if(dst[ngb] > dst[cur] + nw) {
				q.erase( make_pair(dst[ngb], ngb) );

				dst[ngb] = dst[cur] + nw;
				q.insert( make_pair(dst[ngb], ngb) );
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; i++) {
		int ta, tb, tw;
		scanf("%d %d %d", &ta, &tb, &tw);

		g[ta].push_back(tb); g[tb].push_back(ta);
		w[ta].push_back(tw); w[tb].push_back(tw);
	}

	dijkstra(0);

	printf("%d\n", dst[n+1]);
}
