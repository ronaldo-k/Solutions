/*
#include <stdio.h>
#include <vector>
using namespace std;

const int MAXN = 1e5;
int n, r;
int marc[MAXN], qt[MAXN];
vector < int > grafo[MAXN];

int dfs( int v ) {
	int t = 0;
	marc[v] = 1;
	for(int i = 1; i < grafo[v].size(); i++) {
		int viz = grafo[v][i];
		if(marc[viz] == 0) {
			t++;
			dfs(viz);
		}
	}
	printf("\n [ v = %d \n [ t = %d",v,t);
	return t;
}

int main() {
	scanf("%d",&n);
	for(int i = 1; i < n;i++) {
		int ta, tb, tc;
		scanf("%d%d%d",&ta,&tb,&tc);
		if(tc == 1) continue;
		grafo[ta].push_back(tb);
		grafo[tb].push_back(ta);	
	}
	for(int i = 1; i < n;i++) {
		if(marc[i] == 0) {
			int tt = dfs(i);
			r += (tt * (tt-1))/2;	
		}
	}
	printf("\n%d",r);
}
*/

#include <stdio.h>
#include <vector>
using namespace std;

const int MAXN = 1e5;
long long int n, r, c;
int marc[MAXN];
vector < int > grafo[MAXN];

void dfs(int a) {
	c++; //printf("+ ");
	marc[a] = 1;
	for(int i = 0; i < grafo[a].size(); i++) {
		int viz = grafo[a][i];
		if(marc[viz] == 0) {
			marc[viz] = 1;
			dfs(viz);
		}
	}
}

int main() {
	scanf("%lld",&n);
	r = (n * (n-1)) / 2;
	for(int i = 0; i < n-1; i++) {
		int ta, tb, tc;
		
		scanf("%d%d%d",&ta,&tb,&tc);
		ta--; tb--;
		if(tc == 0) {
			grafo[ta].push_back(tb);
			grafo[tb].push_back(ta);
		}
	}
	for(int i = 0; i < n-1; i++) {
		if(marc[i] == 0) {
			c = 0;
			dfs(i);
			//printf("\nc = %d",c);
			r -= (c * (c-1)) / 2;
		}
	}
	printf("\n%lld",r);
}