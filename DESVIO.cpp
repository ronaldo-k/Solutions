// DIJKSTRA – DESVIO (SPOJ)
// 08/09/2019

#include <stdio.h>
#include <vector>
#include <set>
#include <string.h>

using namespace std;

#define debug(args...) //fprintf(stderr, args)

const int MAXN = 300, INF = 2e9;
int n, m, c, k, rend, rbegin, mrk[MAXN], dst[MAXN], pd[MAXN], arrd[MAXN];
vector < int > g[MAXN], w[MAXN];

void dijkstra(int s) {
	set < pair < int, int > > q;

	for(int i = c-1; i < n; i++) {
		if(i != s) {
			mrk[i] = 0; dst[i] = INF;
			q.insert( make_pair(INF, i) );
		}
	}

	mrk[s] = 1; dst[s] = 0;
	q.insert( make_pair(0, s) );

	while(!q.empty()) {
		pair < int, int > cur = *q.begin(); q.erase(q.begin());

		for(int i = 0; i < g[cur.second].size(); i++) {
			int ngb = g[cur.second][i], p = w[cur.second][i];

			if(dst[ngb] > dst[cur.second] + p) {
				q.erase( make_pair(dst[ngb], ngb) );
				dst[ngb] = dst[cur.second] + p;
				q.insert( make_pair(dst[ngb], ngb) );
			}
		}
	}
}

void dijkstra2(int s) {
	set < pair < int, int > > q;

	for(int i = 0; i < n; i++) {
		if(i != s) {
			mrk[i] = 0; dst[i] = INF; arrd[i] = INF;
			q.insert( make_pair(INF, i) );
		}
	}

	mrk[s] = 1; dst[s] = 0;
	q.insert( make_pair(0, s) );

	while(!q.empty()) {
		pair < int, int > cur = *q.begin(); q.erase(q.begin());

		for(int i = 0; i < g[cur.second].size(); i++) {
			int ngb = g[cur.second][i], p = w[cur.second][i];

			if(dst[ngb] > dst[cur.second] + p && ngb >= c) {
				q.erase( make_pair(dst[ngb], ngb) );
				dst[ngb] = dst[cur.second] + p;
				q.insert( make_pair(dst[ngb], ngb) );
			}
			if(ngb < c) {
				arrd[ngb] = min(arrd[ngb], dst[cur.second] + p);
			}
		}
	}
}

void dstfs(int s) {
	set < pair < int, int > > q;

	for(int i = 0; i < c; i++) {
		if(i != s) {
			mrk[i] = 0; pd[i] = INF;
			q.insert( make_pair(INF, i) );
		}
	}

	mrk[s] = 1; pd[s] = 0;
	q.insert( make_pair(0, s) );

	while(!q.empty()) {
		pair < int, int > cur = *q.begin(); q.erase(q.begin());

		for(int i = 0; i < g[cur.second].size(); i++) {
			int ngb = g[cur.second][i], p = w[cur.second][i];

			if(pd[ngb] > pd[cur.second] + p && ngb < c && ngb == cur.second - 1) {
				q.erase( make_pair(pd[ngb], ngb) );
				pd[ngb] = pd[cur.second] + p;
				q.insert( make_pair(pd[ngb], ngb) );
			}
		}
	}
}

int main() {
	while(true) {
		scanf("%d %d %d %d", &n, &m, &c, &k);

		if(n == 0 && m == 0 && k == 0 && c == 0 && k == 0) return 0;

		memset(mrk, 0, sizeof(mrk));
		memset(pd, 0, sizeof(pd));
		memset(arrd, 0, sizeof(arrd));
		memset(dst, 0, sizeof(dst));

		for(int i = 0; i < MAXN; i++) {
			g[i].clear(); w[i].clear();
		}

		rend = c-1;

		for(int i = 0; i < m; i++) {
			int ta, tb, tw;
			scanf("%d %d %d", &ta, &tb, &tw);

			g[ta].push_back(tb); g[tb].push_back(ta);
			w[ta].push_back(tw); w[tb].push_back(tw);
		}

		for(int i = 0; i < c-1; i++) {
			mrk[i] = 1;
		}

		// 1ª busca no grafo: Não se passa por alguma cidade da rota de serviço
		dijkstra(k);
		int ans = dst[c-1];

		debug("After search 1: ans: %d\n", ans);

		for(int i = 0; i < n; i++) {
			debug("dst[%d] = %d\n", i, dst[i]);
		}

		debug("\n");

		memset(mrk, 0, sizeof(mrk));

		// Determinando as distâncias da rota de serviço
		dstfs(c-1);

		debug("After search 2 (Service route):\n");

		for(int i = 0; i < c; i++) {
			debug("pd[%d] = %d\n", i, pd[i]);
		}

		debug("\n");

		memset(mrk, 0, sizeof(mrk));
		memset(dst, 0, sizeof(dst));

		// 2ª busca no grafo: Pode-se passar por alguma cidade da rota de serviço
		// Caso o algoritmo chegue numa cidade da rota de serviço, ele para.
		dijkstra2(k);

		debug("After search 3: \n");

		for(int i = 0; i < c; i++) {
			debug("arrd[%d] = %d\n", i, arrd[i]);
		}

		debug("\n");

		for(int i = 0; i < c; i++) {
			ans = min(ans, arrd[i] + pd[i]);
		}

		printf("%d\n", ans);
	}
}
