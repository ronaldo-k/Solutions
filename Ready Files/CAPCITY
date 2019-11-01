// STRONGLY CONNECTED COMPONENTS - Capital City (SPOJ CAPCITY)

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n, m, countComp, mark[MAXN], compNum[MAXN];

vector < int > ans, exitSort, g[MAXN], r[MAXN];

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
	compNum[cur] = countComp;
	mark[cur] = 1;
	
	for(int i = 0; i < r[cur].size(); i++) {
		int ngb = r[cur][i];
		
		if(mark[ngb] == 0) {
			dfsComps(ngb);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < m; i++) {
		int ta, tb;
		scanf("%d %d", &ta, &tb);
		
		g[ta].push_back(tb);
		r[tb].push_back(ta);
	}
	
	for(int i = 1; i <= n; i++) {
		if(mark[i] == 0) {
			dfsPreCalc(i);
		}
	}
	
	memset(mark, 0, sizeof(mark));
	
	for(int i = n-1; i >= 0; i--) {
		if(mark[exitSort[i]] == 0) {
			dfsComps(exitSort[i]);
			countComp++;
		}
	}
	
	for(int i = 1; i <= n; i++) {
		if(compNum[i] == countComp-1) ans.push_back(i);
	}
	
	sort(ans.begin(), ans.end());
	
	printf("%d\n", ans.size());
	for(int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
}
