// BFS - Fair (Codeforces Round #485 (Div. 2) - D)

#include <stdio.h>
#include <vector>
#include <utility>
#include <deque>
#include <algorithm>
#include <string.h>

using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAXN = 1e5 + 10;

int n, m, k, s, mrk[MAXN], dst[MAXN][110], ans[MAXN];

pair < int, int > w[MAXN];
vector < int > in, g[MAXN];
deque < int > q;

void bfsMultiple(int curw) {
	memset(mrk, 0, sizeof(mrk));
	q.clear();
	
	for(int i = 0; i < in.size(); i++) {
		q.push_back(in[i]);
		dst[in[i]][curw] = 0;
		mrk[in[i]] = 1;
	}
	
	while(!q.empty()) {
		int cur = q.front(); q.pop_front();
		mrk[cur] = 1;
		
		for(int i = 0; i < g[cur].size(); i++) {
			int ngb = g[cur][i];
			
			if(mrk[ngb] != 1) {
				dst[ngb][curw] = dst[cur][curw] + 1;
				mrk[ngb] = 1;
								
				q.push_back(ngb);
			}
		}
	}
}

int main() {
	scanf("%d %d %d %d", &n, &m, &k, &s);
	
	for(int i = 1; i <= n; i++) {
		scanf("%d", &w[i].first);
		w[i].second = i;
	}
	
	for(int i = 1; i <= m; i++) {
		int ta, tb;
		scanf("%d %d", &ta, &tb);
		
		g[ta].push_back(tb);
		g[tb].push_back(ta);
	}
	
	sort(w+1, w + n+1);
	
	for(int i = 1; i <= n; i++) {
		in.push_back(w[i].second);
		
		if(w[i].first != w[i+1].first) {			
			bfsMultiple(w[i].first);
			in.clear();
			continue;
		}
	}
	
	for(int i = 1; i <= n; i++) {
		sort(dst[i] + 1, dst[i] + k+1);
		
		for(int j = 1; j <= s; j++) {
			ans[i] += dst[i][j];
		}
	}
	
	for(int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
}
