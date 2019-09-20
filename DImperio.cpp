#include <stdio.h>
#include <vector>
using namespace std;

const int maxn = 100000;
int n, a = maxn;
int sub[maxn],marc[maxn];
vector <int> grafo[maxn];

int near(int a, int b) {
	if(a - 0 < b - 0) return b;
	else return a;
}

void dfs(int v) {
	marc[v] = 1;
	sub[v] = 1;
	for(int i = 0; i < grafo[v].size(); i++) {
		int viz = grafo[v][i];
		if(marc[viz] == 0) {
			dfs(viz);
			sub[v] += sub[viz];
		}
	}
}

int main() {
	scanf("%d",&n);
	for(int i = 1; i <= n-1; i++) {
		int ta, tb;
		scanf("%d%d",&ta,&tb);
		grafo[ta].push_back(tb);
		grafo[tb].push_back(ta);
	}
	dfs(1);
	for(int i = 1; i <= n; i++) {
		a = near(a, (n-sub[i]-sub[i]));
	}
	printf("%d",a);
}