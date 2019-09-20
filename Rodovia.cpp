#include <stdio.h>
#include <vector>
using namespace std;

const int maxn = 10e4;
int n;
int marc[maxn], outdeg[maxn], indeg[maxn];
vector < int > grafo[maxn];

void dfs( int a ) {
	for(int i = 0; i < grafo[a].size();i++) {
		int cur = grafo[a][i]; //printf("cur = %d, marc[%d] = %d",cur,cur,marc[cur]);
		if(marc[cur] == 0) { marc[cur] = 1; dfs(cur);}
	}
}

int main() {
	scanf("%d",&n);
	for(int i = 1; i <= n; i++) {
		marc[i] = 0;
		int ta, tb;
		scanf("%d%d",&ta,&tb);
		grafo[ta].push_back(tb);
		outdeg[ta]++; indeg[ta]++;
	}
	for(int i = 1; i <= n; i++) {
		//printf("c");
		if(outdeg[i] > 1 || indeg[i] > 1) {
			printf("\nN");
			return 0;
		}
	}
	dfs(1);
	for(int i = 1; i <= n; i++) { //printf("d");
		if(marc[i] == 0) {
			printf("\nN");
			return 0; 
		}
	}
	printf("\nS");
}