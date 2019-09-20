// BFS partindo de multiplos vertices - ULTIMO (SPOJ)


#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAXN = 2e4, INF = 2e9;
int n, k, m, marc[MAXN], dist[MAXN];
vector < int > resp, g[MAXN];
queue < int > qi;

void bfs() {
	// PARTINDO DE MULTIPLOS NOS:
	// Inserir todos os nos de onde se quer comecar na queue da BFS

	queue < int > q;
	while(!qi.empty()) {
		int now = qi.front(); qi.pop();
		dist[now] = 0; marc[now] = 1;
		q.push(now);
	}

	while(!q.empty()) {
		int cur = q.front(); q.pop();

		for(int i = 0; i < g[cur].size(); i++) {
			int ngb = g[cur][i];

			if(marc[ngb] == 0) {
				q.push(ngb);
				marc[ngb] = 1; dist[ngb] = dist[cur] + 1;
			}
		}
	}
}

int main() {
	while(true) {
		scanf("%d %d %d", &n, &k, &m);
		if(n == 0 && k == 0 && m == 0) break;

		// Limpando os vetores, vectors e queues
		for(int i = 1; i <= n; i++) {
			g[i].clear();
		}
		while(!qi.empty()) {
			qi.pop();
		}
		memset(marc, 0, sizeof(marc));
		memset(dist, 0, sizeof(dist));
		resp.clear();

		for(int i= 0; i < k; i++) {
			int ta;
			scanf("%d", &ta);
			qi.push(ta);
		}

		for(int i = 0; i < m; i++) {
			int ta, tb;
			scanf("%d %d", &ta, &tb);

			g[ta].push_back(tb);
			g[tb].push_back(ta);
		}

		bfs();

		int maxDist = -INF;
		for(int i = 1; i <= n; i++) {
			//debug("dist[%d]: %d\n", i, dist[i]);
			maxDist = max(maxDist, dist[i]);
		}

		for(int i = 1; i <= n; i++) {
			if(dist[i] == maxDist && marc[i] == 1) resp.push_back(i);
		}

		for(int i = 0; i < resp.size(); i++) {
			printf("%d ", resp[i]);
		}
		printf("\n");
	}
}
