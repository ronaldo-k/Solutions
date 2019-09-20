#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 510, INF = 2e9;
int n, b, e, m, mrk[4 * MAXN], dst[4 * MAXN];
vector < int > g[4 * MAXN];

void bfs(int v) {
	queue < int > q;

	for(int i = 0; i < 4 * n; i++) {
		mrk[i] = 0; dst[i] = INF;
	}

	mrk[v] = 1;
	dst[v] = 0;
	q.push(v);

	while(!q.empty()) {
		int cur = q.front(); q.pop();

		for(int i = 0; i < g[cur].size(); i++) {
			int ngb = g[cur][i];
			// printf("ngb: %d\n", ngb);

			if(mrk[ngb] == 0) {
				mrk[ngb] = 1;
				dst[ngb] = dst[cur] + 1;

				// printf("dst[%d] = %d\n", ngb, dst[ngb]);

				q.push(ngb);
			}
		}
	}
}

int main() {
	scanf("%d %d %d %d", &n, &b, &e, &m);

	for(int i = 0; i < m; i++) {
		int ta, tb, tw;
		scanf("%d %d %d", &ta, &tb, &tw);

		ta *= 3; tb *= 3;

		if(tw == 1) {
			// printf("adding edge between %d -> %d\n", ta+2, tb);
			g[ ta   ].push_back( tb+1  );
		}
		else {
			// printf("adding edge between %d -> %d and %d -> %d\n", ta, tb+1, ta+1, tb+2);
			g[ ta+1 ].push_back( tb+2 );
			g[ ta+2 ].push_back( tb   );
		}
	}

	b *= 3;
	// printf("beginning with %d\n", b);
	bfs(b);
	e *= 3;

	if(dst[e] == INF && dst[e+1] == INF && dst[e+2] == INF)
		printf("*\n");
	else
		printf( "%d\n", min(dst[e], min(dst[e+1], dst[e+2])) );
}
