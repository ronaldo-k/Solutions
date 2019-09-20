// BRIDGES + UNION-FIND + TREE DIAMETER (DFS) – Sherlock and Highways (HackerEarth)
// Made on: 29-31/08/2019

/*
Sample:
11 13
1 2
1 3
2 4
5 3
5 1
4 6
6 2
2 7
7 8
8 9
9 10
10 11
8 11

Output:
6 5

*/

#include <stdio.h>
#include <utility>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

#define debug(args...) //fprintf(stderr, args)

const int MAXN = 2e5 + 10;
int n, m, dfsTime, maxDstVal, maxDstId, cEdgNum;
int mrkB[MAXN], mrkD[MAXN], tim[MAXN], low[MAXN], rep[MAXN], dpt[MAXN], dst[MAXN], fat[MAXN];

vector < int > g[MAXN], c[MAXN];
// t is the compressed graph, where every component (when all bridges are removed) is a single node

//-----------------------------------------------------------//
// UNION-FIND:

int find(int v) {
	debug("F: %d\n", v);
	if(rep[v] == v)return v;
	else return rep[v] = find(rep[v]);
}

void join(int a, int b){
	debug("J: %d %d\n", a, b);
	a = find(a); b = find(b);

	if(a == b) return;

	if(dpt[a] > dpt[b]) {
		rep[b] = a;
		return;
	}
	rep[a] = b;

	if(dpt[a] == dpt[b]) {
		dpt[b]++;
	}
}


//-----------------------------------------------------------//
// DFS:

void dfsBridge(int v, int f) {
	debug("B: %d %d\n", v, f);

	mrkB[v] = 1;
	tim[v] = low[v] = dfsTime++;

	for(int i = 0; i < g[v].size(); i++) {
		int ngb = g[v][i];

		if(v == fat[ngb]) continue;
		if(mrkB[ngb] == 1){
			low[v] = min(low[v], tim[ngb]);
		}
		else {
			fat[ngb] = v;
			dfsBridge(ngb, v);

			debug("ANALYSING: %d %d, low vs. tim: %d %d\n", ngb, v, low[ngb], tim[v]);

			if(low[ngb] < tim[v]) {
				debug("JOINING: %d %d\n", ngb, v);
				join(ngb, v);
			}
			low[v] = min(low[v], low[ngb]);
		}
	}
}

void dfsDiameter(int v) {
	debug("D: %d\n", v);
	mrkD[v] = 1;

	for(int i = 0; i < c[v].size(); i++) {
		debug(" -> i: %d\n", i);
		int ngb = c[v][i];

		if(mrkD[ngb] == 0) {
			cEdgNum++;
			dst[ngb] = dst[v] + 1;
			debug(" -> dst: %d %d\n", dst[ngb], dst[v]);

			if(dst[ngb] > maxDstVal) {
				debug("MAXDIST UPDATE: %d %d\n", ngb, dst[ngb]);

				maxDstVal = dst[ngb];
				maxDstId = ngb;
			}

			dfsDiameter(ngb);
		}
	}
}

//-----------------------------------------------------------//
// MAIN:

int main() {
	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; i++) {
		int ta, tb;

		scanf("%d %d", &ta, &tb);

		g[ta].push_back(tb);
		g[tb].push_back(ta);
	}

	for(int i = 0; i <= n; i++) {
		rep[i] = i;
		dst[i] = 0;
	}

	dfsBridge(1, 1);

	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < g[i].size(); j++) {
			int ngb = g[i][j];

			if(low[ rep[ngb] ] == tim[i]) {
				c[i].push_back( rep[ngb] );
				c[ rep[ngb] ].push_back(i);

				debug("GF: %d -> %d\n", i, rep[ngb]);
			}
		}
	}

	dfsDiameter(1);

	int ans1 = cEdgNum;
	maxDstVal = 0;
	memset(mrkD, 0, sizeof(mrkD));
	memset(dst, 0, sizeof(dst));
	debug("Now for the second one:\n");

	dfsDiameter(maxDstId);

	printf("%d %d\n", ans1, maxDstVal);
}
