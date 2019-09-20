#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 10;

vector < int > grafo[MAXN];
int nivel[MAXN], marc[MAXN], qtdNivel[MAXN], qtdVinda[MAXN], maxNivel;

void dfs(int v) {
	marc[v] = 1;

	for(int i = 0; i < grafo[i].size(); i++) {
		int viz = grafo[v][i];

		if(marc[viz] == 0) {
			nivel[viz] = nivel[v] + 1;
			dfs(viz);
		}
	}
}

int main() {
	int n, m;

	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; i++) {
		int ta;

		scanf("%d", &ta);

		grafo[i].push_back(ta);
		grafo[ta].push_back(i);
	}

	dfs(0);

	for(int i = 1; i <= n; i++) {
		qtdNivel[ nivel[i] ]++;
		maxNivel = max(maxNivel, nivel[i]);
		printf("nivel[%d] = %d\n", i, nivel[i]);
	}

	for(int i = 1; i <= m; i++) {
		int ta;

		scanf("%d", &ta);

		qtdVinda[ nivel[ta] ]++;
	}

	for(int i = 0; i <= maxNivel; i++) {
		printf("%.2f\n", ((float)qtdVinda[i] / (float)qtdNivel[i]) * 100 );
	}
}
