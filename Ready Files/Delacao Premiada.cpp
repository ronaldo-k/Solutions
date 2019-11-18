// DFS – Delação Premiada (?)

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

#define debug(args...) //fprintf(stderr, args)

const int MAXN = 1e5 + 10;

int n, k, ans, curK, mrk[MAXN], dpt[MAXN], maxDpt[MAXN];
pair < int, int > path[MAXN];

vector < int > g[MAXN];

void dfs1(int cur){
	// Determina as profundidades máximas dos caminhos do vértice v.

	mrk[cur] = 1;
	maxDpt[cur] = dpt[cur];

	for(int i = 0; i < g[cur].size(); i++) {
		int ngb = g[cur][i];

		if(mrk[ngb] == 0) {
			dpt[ngb] = dpt[cur] + 1;
			dfs1(ngb);
			maxDpt[cur] = max(maxDpt[cur], maxDpt[ngb]);
		}
	}
}

void dfs2(int cur, int w) {
	// Determina a profundidade de cada nó em relação a seu próprio caminho.
	// Argumentos:
	//	- cur: Vértice atual
	//	- w  : Tamanho do caminho até o vizinho superior

	mrk[cur] = 2;
	// A maior profundidade máxima encontrada nos vizinhos e o índice do vizinho que pertence ao maior caminho
	int valMD, idMD;
	valMD = idMD = -1;

	for(int i = 0; i < g[cur].size(); i++){
		int ngb = g[cur][i];

		if(valMD < maxDpt[ngb]) {
			valMD = maxDpt[ngb];
			idMD = ngb;
		}
	}

	// Quando o vértice cur é um folha
	if(idMD == -1) {
		return;
	}

	if(mrk[idMD] == 1) {
		path[idMD].first = w+1;
		dfs2(idMD, w + 1);
	}

	for(int i = 0; i < g[cur].size(); i++) {
		int ngb = g[cur][i];

		if(mrk[ngb] == 1) {
			path[ngb].first = 1;
			dfs2(ngb, 1);
		}
	}
}

int main() {
	scanf("%d %d", &n, &k);

	for(int i = 2; i <= n; i++) {
		int ta;
		scanf("%d", &ta);

		g[ta].push_back(i);
		path[ta].second++;
	}

	dfs1(1);
	dfs2(1, 1);

//	debug("maxDpt:\n");
//	for(int i = 1; i <= n; i++) {
//		debug("[%d] -> %d\n", i, maxDpt[i]);
//	}
//
//	debug("pathDpt:\n");
//	for(int i = 1; i <= n; i++) {
//		debug("[%d] -> %d\n", i, path[i].first);
//	}

	sort(path + 1, path + n + 1);

	for(int i = n; (i >= 0 && curK < k); i--) {
//		debug("i = %d, curK = %d, pathDpt = %d, inDeg[] = %d\n", i, curK, path[i].first, path[i].second);
		if(path[i].second == 0) {
			curK++;
			ans += path[i].first;
		}
	}

	printf("%d\n", ans);
}
