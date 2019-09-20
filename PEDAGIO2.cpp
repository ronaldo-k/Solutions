// BFS Convencional – PEDAGIO (SPOJ)
// Link: https://br.spoj.com/problems/PEDAGIO/

#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAXN = 100;
int c, e, l, p, z, dist[MAXN], marc[MAXN];

vector < int > g[MAXN];

void bfs(int b) {
	queue < int > q;
	marc[b] = 1;
	dist[b] = 0;

	q.push(b);

	while(!q.empty()) {
		int cur = q.front(); q.pop();

		for(int i = 0; i < g[cur].size(); i++) {
			int ngb = g[cur][i];

			if(marc[ngb] == 0) {
				q.push(ngb);
				dist[ngb] = dist[cur] + 1;
				marc[ngb] = 1;
			}
		}
	}
}

int main() {
	while(true) {
		z++;
		for(int i = 0; i <= MAXN-2; i++) {
			g[i].clear();
		}

		scanf("%d %d %d %d", &c, &e, &l, &p);
		if(c == 0 && e == 0 && l == 0 && p == 0) break;

		memset(dist, 0, sizeof(dist));
		memset(marc, 0, sizeof(marc));

		for(int i = 0; i < e; i++) {
			int ta, tb;
			scanf("%d %d", &ta, &tb);

			g[ta].push_back(tb);
			g[tb].push_back(ta);
		}

		bfs(l);

		printf("Teste %d\n", z);
		for(int i = 1; i <= c; i++) {
			if(dist[i] <= p && dist[i] != 0) printf("%d ",i);
		}
	}
}
