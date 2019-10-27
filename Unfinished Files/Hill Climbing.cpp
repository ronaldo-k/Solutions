#include <stdio.h>
#include <algorithm>
#include <vector>

/* No caso de teste do statement, o grafo formado deve ser:
6 5
5 4
4 3
3 2
5 1
*/

using namespace std;

#define debug(args...) fprintf(stderr, args);

struct point {
	long long int x, y;

	point(long long int tx = 0, long long int ty = 0){
		x = tx;
		y = ty;
	}
	struct point operator-(struct point a) {
		struct point aux;
		aux.x = x - a.x;
		aux.y = y - a.y;
		return aux;
	}
	bool operator<(struct point a) const {
		if(x == a.x) return y < a.y;
		return x > a.x;
	}
};

long long int cross(struct point a, struct point b) {
	return (a.x * b.y) - (a.y * b.x);
}

const int MAXN = 1e5 + 10, MAXL = 20, INF = 2e9;

int n, m, mrk[MAXN], dpt[MAXN], fat[MAXN], dpAnc[MAXN][MAXL];
struct point v[MAXN];
vector < int > g[MAXN];
vector < pair < int, struct point > > hull;

void buildHull() {
	int last = -1;
	for(int i = 0; i < n; i++) {
		while(last >= 1 && cross(hull[last].second - hull[last-1].second, v[i] - hull[last-1].second) >= 0) {
			last--;
			hull.pop_back();
		}

		last++;
		hull.push_back(make_pair(i, v[i]));

		if(last >= 1) { // REVER!
		   // debug("INSERTING %d %d\n", hull[last].first+1, hull[last-1].first+1);
		   g[hull[last].first+1].push_back(i);
		   g[i].push_back(hull[last].first+1);
	   	}
	}

	// for(int i = 1; i < hull.size(); i++) {
	// 	debug("IN %d %d\n", hull[i].first+1, hull[i-1].first+1);
	// 	g[hull[i].first+1].push_back(hull[i-1].first+1);
	// 	g[hull[i-1].first+1].push_back(hull[i].first+1);
	// }
}

void dfs(int cur) {
	mrk[cur] = 1;

	for(int i = 0; i < g[cur].size(); i++) {
		int ngb = g[cur][i];

		if(mrk[ngb] == 0) {
			dpt[ngb] = dpt[cur] + 1;
			fat[ngb] = dpAnc[ngb][0]= cur;
			dfs(ngb);
		}
	}
}

void solve() {
	for(int i = 1; i < MAXL; i++) {
		for(int j = 1; j <= n; j++) {
			dpAnc[j][i] = dpAnc[ dpAnc[j][i-1] ][i-1];
			//debug("dpAnc[%d][%d] = %d\n", j, i, dpAnc[j][i]);
		}
	}
}

int LCA(int a, int b) {
	int oa = a, ob = b;
	if(dpt[a] > dpt[b]) swap(a, b);

	debug("1. a = %d (dpt: %d), b = %d (dpt: %d)\n", a, dpt[a], b, dpt[b]);

	if(dpt[a] < dpt[b]) {
		int d = dpt[b] - dpt[a];

		for(int i = 0; i < MAXL; i++) {
			int curBit = d & (1<<i);

			if(curBit) {
				b = dpAnc[b][i];
			}
		}
	}

	debug("2. a = %d (dpt: %d), b = %d (dpt: %d)\n", a, dpt[a], b, dpt[b]);

	if(a == b && oa <= a && ob <= b) return a;

	for(int i = MAXL-1; i >= 0; i--) {
		if(dpAnc[a][i] != dpAnc[b][i]) {
			b = dpAnc[b][i]; a = dpAnc[a][i];
		}
	}

	debug("3. a = %d (dpt: %d), b = %d (dpt: %d)\n", a, dpt[a], b, dpt[b]);

	return a;
}

int main() {
	scanf("%d", &n);
	for(int i = n-1; i >= 0; i--) {
		scanf("%lld %lld", &v[i].x, &v[i].y);
	}

	buildHull();

	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < g[i].size(); j++) {
			debug("%d -> %d\n", i, g[i][j]);
		}
	}

	fat[n] = n;
	dfs(n);

	for(int i = 1; i <= n; i++) {
		debug("dpt[%d] = %d, fat[%d] = %d\n", i, dpt[i], i, fat[i]);
	}

	solve();

	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		int ta, tb;
		scanf("%d %d", &ta, &tb);

		printf("%d\n", LCA(ta, tb));
	}
}
