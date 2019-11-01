// STRONGLY CONNECTED COMPONENTS - True Friends (SPOJ TFRIENDS) 

#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

const int MAXN = 110;

int t, n, mark[MAXN], ans;

vector < int > exitSort, g[MAXN], r[MAXN];

void dfsPreCalc(int cur) {
	mark[cur] = 1;
	
	for(int i = 0; i < g[cur].size(); i++) {
		int ngb = g[cur][i];
		
		if(mark[ngb] == 0) {
			dfsPreCalc(ngb);
		}
	}
	
	exitSort.push_back(cur);
}

void dfsComps(int cur) {
	mark[cur] = 1;
	
	for(int i = 0; i < r[cur].size(); i++) {
		int ngb = r[cur][i];
		
		if(mark[ngb] == 0) {
			dfsComps(ngb);
		}
	}
}

int main() {
	scanf("%d", &t);
	
	for(int c = 0; c < t; c++) {
		ans = 0;
		memset(mark, 0, sizeof(mark));
		exitSort.clear();
		
		for(int i = 0; i < MAXN; i++) {
			g[i].clear(); r[i].clear();
		}
		
		scanf("%d", &n);
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				char ta;
				scanf(" %c", &ta);
				
				if(ta == 'Y') {
					g[i].push_back(j);
					r[j].push_back(i);
				}
			}
		}
		
		for(int i = 0; i < n; i++) {
			if(mark[i] == 0) {
				dfsPreCalc(i);
			}
		}
		
		memset(mark, 0, sizeof(mark));
		
		for(int i = n-1; i >= 0; i--) {
			if(mark[exitSort[i]] == 0) {
				dfsComps(exitSort[i]);
				ans++;
			}
		}
		
		printf("%d\n", ans);
	}
}
