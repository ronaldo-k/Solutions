// BIPARTITE GRAPH – MESA (Revisited) (SPOJ)
// Made on: 02/09/2019

#include <stdio.h>
#include <vector>
#include <utility>
#include <string.h>

using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAXN = 110;
bool isValid = true;
int n, m, mk[MAXN], dpt[MAXN], testCase;

vector < int > g[MAXN];
vector < pair < int, int > > e;

void dfs(int v) {
	mk[v] = 1;

	for(int i = 0; i < g[v].size(); i++) {
		int ngb = g[v][i];

		if(mk[ngb] == 0) {
			dpt[ngb] = dpt[v] + 1;
			dfs(ngb);
		}
	}
}

int main() {
	while(scanf("%d %d", &n, &m) != EOF) {
		isValid = true;
		e.clear();
		memset(mk, 0, sizeof(mk));
		memset(dpt, 0, sizeof(dpt));

		for(int i = 1; i <= n; i++) {
			g[i].clear();
		}

		testCase++;
		for(int i = 0; i < m; i++) {
			int ta, tb;
			scanf("%d %d", &ta, &tb);

			g[ta].push_back(tb);
			g[tb].push_back(ta);
			e.push_back( make_pair(ta, tb) );
		}

		for(int i = 1; i <= n; i++) {
			if(mk[i] == 0) dfs(i);
		}

		for(int i = 0; i < m; i++) {
			if(dpt[ e[i].first ] % 2 == dpt[ e[i].second ] % 2) {
				isValid = false;
			}
		}

		if(isValid) printf("Instancia %d\nsim\n\n", testCase);
		else printf("Instancia %d\nnao\n\n", testCase);
	}
}
