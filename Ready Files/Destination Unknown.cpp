// DIJKSTRA - Destination Unknown (Kattis BAPC 2013)
/*
WARNING: The unusual conventions used in this code are the following:
> p1 and p2 (Called g and h in the problem statement, respectively):
	Between p1 and p2, p1 is necessarily the closest to the beggining node S
> dst[i][k]:
	- k = 0: Distance measured from beggining node S
	- k = 1: Distance measured from node p1
	- k = 2: Distance measured from node p2
*/

#include <stdio.h>
#include <vector>
#include <set>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAXN = 2010, INF = 2e9;

int n, m, t, s, p1, p2, pw, dst[MAXN][3];

set < pair < int, int > > q;
vector < int > g[MAXN], w[MAXN], e, ans;

void dijkstra(int b, int id) {	
	for(int i = 1; i <= n; i++) {
		dst[i][id] = INF;
		q.insert(make_pair(INF, i));
	}
	
	dst[b][id] = 0;
	q.insert(make_pair(0, b));
	
	while(!q.empty()) {
		int cur = q.begin()->second; q.erase(q.begin());
		
		for(int i = 0; i < g[cur].size(); i++) {
			int ngb = g[cur][i], nw = w[cur][i];
			
			if(dst[ngb][id] > dst[cur][id] + nw) {
				q.erase(make_pair(dst[ngb][id], ngb));
				dst[ngb][id] = dst[cur][id] + nw;
				q.insert(make_pair(dst[ngb][id], ngb));
			}
		}
	}
}

int main() {
	int tc;
	scanf("%d", &tc);
	
	for(int cases = 0; cases < tc; cases++) {
		memset(dst, 0, sizeof(dst));
		ans.clear(); e.clear(); q.clear();
				
		for(int i = 1; i < MAXN; i++) {
			g[i].clear(); w[i].clear();
		}
		
		scanf("%d %d %d %d %d %d", &n, &m, &t, &s, &p1, &p2);
		
		for(int i = 0; i < m; i++) {
			int ta, tb, tw;
			scanf("%d %d %d", &ta, &tb, &tw);
			g[ta].push_back(tb); g[tb].push_back(ta);
			w[ta].push_back(tw); w[tb].push_back(tw);
			
			if(p1 == ta && p2 == tb) pw = tw;
			swap(ta, tb);
			if(p1 == ta && p2 == tb) pw = tw;
		}
		for(int i = 0; i < t; i++) {
			int ta;
			scanf("%d", &ta);
			e.push_back(ta);
		}
			
		dijkstra(s, 0);
		if(dst[p1][0] > dst[p2][0]) swap(p1, p2);	
		
		dijkstra(p1, 1);
		dijkstra(p2, 2);
		
		for(int i = 0; i < t; i++) {
			if(dst[e[i]][0] == dst[s][1] + pw + dst[e[i]][2]) ans.push_back(e[i]);
		}
		
		sort(ans.begin(), ans.end());
		
		for(int i = 0; i < ans.size(); i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
}
