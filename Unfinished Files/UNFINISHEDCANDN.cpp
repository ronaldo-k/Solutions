#include <stdio.h>
#include <vector>
#include <set>
#include <utility>
#include <string.h>
#include <algorithm>

using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAXN = 5010, INF = 2e9;

int n, beg, endC, endN, m, ansBoth, ansC, ansN, dst[4][MAXN];

vector < int > g[MAXN], w[MAXN];
vector < pair < int, int > > pathC, pathN;
set < pair < int, int > > q;

void printStats() {
	debug("Distances:\n");
	for(int id = 0; id < 3; id++) {
		for(int i = 1; i <= n; i++) {
			debug("dst[%d][%d] = %d\n", id, i, dst[id][i]);
		}
	}

	debug("\nPaths:\n");
	debug("pathC:\n");
	for(int i = 0; i < pathC.size(); i++) {
		debug("%d ", pathC[i].second);
	}
	debug("\npathN:\n");
	for(int i = 0; i < pathN.size(); i++) {
		debug("%d ", pathN[i].second);
	}
	debug("\n");
}

void dijkstra(int id, int tb) {
	for(int i = 1; i <= n; i++) {
		dst[id][i] = INF;
		q.insert(make_pair(INF, tb));
	}

	dst[id][tb] = 0;
	q.insert(make_pair(0, tb));

	while(!q.empty()) {
		int cur = q.begin()->second; q.erase(q.begin());

		for(int i = 0; i < g[cur].size(); i++) {
			int ngb = g[cur][i], nw = w[cur][i];

			if(dst[id][ngb] > dst[id][cur] + nw) {
				q.erase(make_pair(dst[id][ngb], ngb));
				dst[id][ngb] = dst[id][cur] + nw;
				q.insert(make_pair(dst[id][ngb], ngb));
			}
		}
	}
}

int main() {
	while(true) {
		ansBoth = ansC = ansN = 0;
		memset(dst, 0, sizeof(dst));
		for(int i = 0; i < MAXN; i++) g[i].clear(), w[i].clear();
		pathC.clear(), pathN.clear();
		q.clear();

		scanf("%d %d %d %d %d", &n, &beg, &endC, &endN, &m);

		if(n == -1) break;

		for(int i = 0; i < m; i++) {
			int ta, tb, tw;
			scanf("%d %d %d", &ta, &tb, &tw);

			g[ta].push_back(tb); g[tb].push_back(ta);
			w[ta].push_back(tw); w[tb].push_back(tw);
		}

		dijkstra(0, beg);
		dijkstra(1, endC);
		dijkstra(2, endN);

		for(int i = 1; i <= n; i++) {
			debug("%d + %d = %d\n", dst[0][i], dst[1][i], dst[0][endC]);
			debug("%d + %d = %d\n", dst[0][i], dst[2][i], dst[0][endN]);
			if(dst[0][i] + dst[1][i] == dst[0][endC]) pathC.push_back( make_pair(dst[0][i], i) );
			if(dst[0][i] + dst[2][i] == dst[0][endN]) pathN.push_back( make_pair(dst[0][i], i) );
		}

		sort(pathC.begin(), pathC.end());
		sort(pathN.begin(), pathN.end());

		for(int i = 0; i < min(pathC.size(), pathN.size()); i++) {
			if(pathC[i+1].second != pathN[i+1].second) {
				ansBoth = pathN[i].first;
				break;
			}
		}
		for(int i = pathC.size()-1; i >= 0; i--) {
			if(pathC[i].second != pathN[i].second) continue;
			else {
				ansC = pathC[i].first;
				debug("Summing %d (ANSC)\n", pathC[i].first);
			}
		}
		for(int i = 0; i < pathN.size(); i++) {
			if(pathC[i].second == pathN[i].second) continue;
			else {
				ansN = pathN[i].first;
				debug("Summing %d (ANSN)\n", pathN[i].first);
			}
		}

		ansC -= ansBoth, ansN -= ansBoth;

		printStats();

		printf("%d %d %d\n", ansBoth, ansC, ansN);
	}
}
