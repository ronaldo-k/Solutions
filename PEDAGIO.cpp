#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 50;
int c, e, l, p;
int dist[maxn],marc[maxn];
vector <int> grafo[maxn];

void bfs(int a) { 
	queue <int> q;
	q.push(a);
	
	while(!q.empty()){
		int v = q.front(); q.pop();
		for(int i = 0; i < grafo[a].size(); i++) {
			int viz = grafo[a][i];
			
			if(marc[viz] == 0) {
				marc[viz] = 1;
				q.push(viz);
				dist[viz] = dist[a] + 1;
			}
		}
	}
}

int main() {
	int cn = 0;
	while(true) {
		cn++;
		scanf("%d%d%d%d",&c,&e,&l,&p);
		if(c == 0 && e == 0) break;
		
		for(int i = 0; i < maxn; i++) {
			dist[i] = 0;
			marc[i] = 0;
		}
		
		for(int i = 0; i < e; i++) {
			int ta, tb;
			scanf("%d%d",&ta,&tb);
			grafo[ta].push_back(tb);
			grafo[tb].push_back(ta);			
		}
		
		bfs(l);
		printf("Teste %d\n",cn);
		for(int i = 0; i < c; i++) {
			if(dist[i] == p) {
				printf("%d ",i);
			}
		}
		printf("\n");
	}
}