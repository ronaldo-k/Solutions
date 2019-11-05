#include <stdio.h>
#include <vector>
#include <set>
#include <utility>
#include <string.h>

using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAXN = 10010, INF = 2.1e9;

int n, m, dst[2][MAXN], ans;

vector < int > g[MAXN], w[MAXN];
set < pair < int, int > > q, p;

void dijkstra(int beg, int id) {
	for(int i = 0; i < n; i++) {
		dst[id][i] = INF;
	}
	
	dst[id][beg] = 0;
	q.insert( make_pair(0, beg) );
	
	while(!q.empty()) {
		int cur = q.begin()->second, cw = q.begin()->first;
		q.erase(q.begin());
				
		for(int i = 0; i < g[cur].size(); i++) {
			int ngb = g[cur][i], nw = w[cur][i];
			
			if(dst[id][ngb] > dst[id][cur] + nw) {
				q.erase( make_pair(dst[id][ngb], ngb) );
				dst[id][ngb] = dst[id][cur] + nw;
				q.insert( make_pair(dst[id][ngb], ngb) );
			}
		}
	}
}

int main() {
	while(scanf("%d %d", &n, &m) != EOF) {
		ans = 0;
		memset(dst, 0, sizeof(dst));
		p.clear();
		for(int i = 0; i < n; i++) {
			g[i].clear(); w[i].clear();
		}
		
		for(int i = 0; i < m; i++) {
			int ta, tb, tw;
			scanf("%d %d %d", &ta, &tb, &tw);
			g[ta].push_back(tb); g[tb].push_back(ta);
			w[ta].push_back(tw); w[tb].push_back(tw);
		}
		
		dijkstra(0, 0);
		q.clear();
		
		dijkstra(n-1, 1);
		q.clear();
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < g[i].size(); j++) {
				int ngb = g[i][j], nw = w[i][j];
				//debug("%d + %d + %d ?= %d\n", dst[0][i], dst[1][ngb], nw, dst[0][n-1]);
				
				if(dst[0][i] + dst[1][ngb] + nw == dst[0][n-1] && p.find(make_pair(i, ngb)) == p.end()) {
					ans += nw;
					p.insert(make_pair(ngb, i)); p.insert(make_pair(i, ngb));
				}
			}
		}
		
		printf("%d\n", ans * 2);
	}
}
