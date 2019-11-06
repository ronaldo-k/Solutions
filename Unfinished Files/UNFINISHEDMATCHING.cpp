#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAXN = 5e4 + 10;

int n, m, p, ans, mrk[MAXN], matchN[MAXN], matchM[MAXN];

vector < int > g[MAXN];

bool dfs(int cur) {
	for(int i = 0; i < g[cur].size(); i++) {
		int ngb = g[cur][i];
		
		if(mrk[ngb] == 1) continue;
		mrk[ngb] = 1;
		
		if(matchN[ngb] <= 0 || dfs(matchN[ngb])) {
			matchN[cur] = ngb;
			matchM[ngb] = cur;
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d %d %d", &n, &m, &p);
	
	for(int i = 0; i < p; i++) {
		int ta, tb;
		scanf("%d %d", &ta, &tb);
		ta--; tb--;
		
		g[ta].push_back(tb);
	}
	
	for(int i = 0; i < n; i++) matchN[i] = -1;
	for(int i = 0; i < m; i++) matchM[i] = -1;
	bool aux = true;
	
	while(aux) {
		memset(mrk, 0, sizeof(mrk));
		aux = false;
		
		for(int i = 0; i < n; i++) {
			if(matchN[i] >= 0) continue;
			if(dfs(i)) {
				aux = true;
				ans++;
			}
		}
	}
	
//	for(int i = 0; i < n; i++) {
//		printf("[%d] = matchN: %d, matchM: %d\n", i, matchN[i], matchM[i]);
//	}
	
	printf("%d\n", ans);
}
