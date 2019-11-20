#include <stdio.h>
#include <vector>
#include <set>
#include <utility>
#include <string.h>

using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAXN = 10010, INF = 2.1e9;

int n, m, b, e, dst[3][MAXN], dstc[MAXN], ans;

vector < int > g[MAXN], w[MAXN];
set < pair < int, int > > q, p;

void dijkstra(int beg, int id) {
	for(int i = 0; i < n; i++) {
		dst[id][i] = INF;
	}

	dst[id][beg] = 0;
	q.insert( make_pair(0, beg) );

	while(!q.empty()) {
		int cur = q.begin()->second;
		q.erase(q.begin());

		for(int i = 0; i < g[cur].size(); i++) {
			int ngb = g[cur][i], nw = w[cur][i];
			
			if(dst[id][ngb] > dst[id][cur] + nw) {
				q.erase( make_pair(dst[id][ngb], ngb) );
				dst[id][ngb] = dst[id][cur] + nw;
				q.insert( make_pair(dst[id][ngb], ngb) );
			}
		}
	}
}

void dijkstraCheck(int beg) {
	for(int i = 0; i < n; i++) {
		dstc[i] = INF;
	}

	dstc[beg] = 0;
	q.insert( make_pair(0, beg) );

	while(!q.empty()) {
		int cur = q.begin()->second;
		q.erase(q.begin());

		for(int i = 0; i < g[cur].size(); i++) {
			int ngb = g[cur][i], nw = w[cur][i];
			
			if(dstc[ngb] > dstc[cur] + nw && p.find(make_pair(cur, ngb)) == p.end()) {
				q.erase( make_pair(dstc[ngb], ngb) );
				dstc[ngb] = dstc[cur] + nw;
				q.insert( make_pair(dstc[ngb], ngb) );
			}
		}
	}
}

int main() {
	scanf("%d %d %d %d", &n, &m, &b, &e);

	for(int i = 0; i < m; i++) {
		int ta, tb, tw;
		scanf("%d %d %d", &ta, &tb, &tw);
		g[ta].push_back(tb); g[tb].push_back(ta);
		w[ta].push_back(tw); w[tb].push_back(tw);
	}

	dijkstra(b, 0);
	q.clear();

	dijkstra(e, 1);
	q.clear();

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < g[i].size(); j++) {
			int ngb = g[i][j], nw = w[i][j];
			debug("%d + %d + %d = %d ?= %d\n", dst[0][i], dst[1][ngb], nw, dst[0][i] + dst[1][ngb] + nw, dst[0][e]);

			if(dst[0][i] + dst[1][ngb] + nw == dst[0][e] && p.find(make_pair(i, ngb)) == p.end()) {
				p.insert(make_pair(ngb, i)); p.insert(make_pair(i, ngb));
			}
		}
	}
	
	dijkstraCheck(b);

	printf("%d\n", dstc[e]);
}
