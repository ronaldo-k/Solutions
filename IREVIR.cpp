#include <stdio.h>
#include <vector>
using namespace std;

const int MAXN = 2100;

int n, m, s;
int marc[MAXN], marcR[MAXN];

vector < int > grafo[MAXN];
vector < int > reverso[MAXN];

bool dfs2( int a ) {
	if(marc[a] == 0) {
		marc[a] = 1;
		for(int i = 0; i < reverso[a].size(); i++) {
			int viz = reverso[a][i];
			if(viz == s) {
				return true;
			}
			if(marc[viz] == 0) {
				marc[viz] = 1;
				dfs2(viz);
			}
		}
	}
	return false;
}

void dfs( int a ) {
	if(marc[a] == 0) {
		marc[a] = 1; printf("a = %d, marc[a] = %d",a,marc[a]);
		for(int i = 0; i < grafo[a].size(); i++) {
			int viz = grafo[a][i];
			if(marc[viz] == 0) {
				marc[viz] = 1; printf("marc[%d] = %d",viz,marc[viz]);
				dfs(viz);
			}
		}
	}
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i = 0; i < m; i++) {
		int ta, tb, tc;
		scanf("%d%d%d",&ta,&tb,&tc);
		ta--; tb--;
		if(tc == 2) {
			grafo[ta].push_back(tb);
			grafo[tb].push_back(ta);
			reverso[ta].push_back(tb);
			reverso[tb].push_back(ta);
		}
		else {
			grafo[ta].push_back(tb);
			reverso[tb].push_back(ta);
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			marc[j] = 0;
		}
		dfs(i);
		for(int j = 0; j < n; j++) {
			printf("j = %d, marc[j] = %d", j, marc[j]);
			if(marc[j] == 0) {
				printf("0\n");
			}
		}
	}
	
	for(int i = 0; i < n; i++) {
		if(!dfs2(i)) {
			printf("0\n");
			return 0;
		}
	}
	printf("1\n");
}