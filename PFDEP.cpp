// Ordenacao topologica - PFDEP (SPOJ)

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <string.h>

using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAXN  = 110;
int n, m, inDeg[MAXN], marc[MAXN];
vector < int > g[MAXN], resp;
set < int > q;

int main() {
	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; i++) {
		int ta, tb, k;
		scanf("%d %d", &ta, &k);

		for(int i = 0; i < k; i++) {
			scanf("%d", &tb);
			inDeg[ta]++;
			g[tb].push_back(ta);
		}
	}

	for(int i = 1; i <= n; i++) {
		if(inDeg[i] == 0) {
			marc[i] = 1;
			q.insert(i);
		}
	}

	while(!q.empty()) {
		int cur = *q.begin(); q.erase(cur);
		resp.push_back(cur);

		for(int i = 0; i < g[cur].size(); i++) {
			int ngb = g[cur][i];
			inDeg[ngb]--;

			if(inDeg[ngb] == 0 && marc[ngb] == 0) {
				marc[ngb] = 1;
				q.insert(ngb);
			}
		}
	}

	for(int i = 0; i < resp.size(); i++) {
		printf("%d ", resp[i]);
	}
	printf("\n");
}
