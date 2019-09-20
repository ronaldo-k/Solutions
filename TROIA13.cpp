#include <stdio.h>
#include <vector>
using namespace std;

const int MAXN = 1e5;
int n, m, r, marc[MAXN];

vector < int > grafo[MAXN];

void dfs(int v) {
	marc[v] = 1;

	for(int i = 0; i < grafo[v].size(); i++) {
		int viz = grafo[v][i];

		if(marc[viz] == 0) {
			dfs(viz);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; i++) {
		int ta, tb;
		scanf("%d %d", &ta, &tb);

		grafo[ta].push_back(tb);
		grafo[tb].push_back(ta);
	}

	for(int i = 1; i <= n; i++) {
		if(marc[i] == 0) {
			//printf("i = %d | New component\n", i);
			dfs(i);
			r++;
		}
	}

	printf("%d\n", r);
}
