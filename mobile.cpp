#include <stdio.h>
#include <vector>
using namespace std;

const int MAXN = 1e5;

int n, marc[MAXN], sub[MAXN], nivel[MAXN];

vector < int > grafo[MAXN];

void dfs(int v) {
	marc[v] = 1;
	sub[v] = 1;

	for(int i = 0; i < grafo[v].size(); i++) {
		int viz = grafo[v][i];

		if(marc[viz] == 0) {
			nivel[viz] = nivel[v] + 1;
			dfs(viz);
			sub[v] += sub[viz];
		}
	}
}

bool dfs2(int v) {
	marc[v] = 2;
	int qtdSub = -1;

	for(int i = 0; i < grafo[v].size(); i++) {
		int viz = grafo[v][i];

		if(marc[viz] == 1) {
			//printf("qtdSub = %d, v = %d, viz = %d\n", qtdSub, v, viz);
			if(qtdSub == -1) {
				qtdSub = sub[viz];
			}
			else if(qtdSub != sub[viz]) {
				return false;
			}

			if(!dfs2(viz)) return false;
		}
	}

	return true;
}

int main() {
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		int ta, tb;
		scanf("%d %d", &ta, &tb);

		grafo[ta].push_back(tb);
		grafo[tb].push_back(ta);
	}

	dfs(0);

	if(dfs2(0)) printf("bem\n");
	else printf("mal\n");
}
