#include <stdio.h>
#include <queue>
using namespace std;

const int maxn = 1010;
int n, m, r;
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
int p[maxn][maxn], marc[maxn][maxn], dist[maxn][maxn];

void grid(int x, int y) {
	queue < int > q;
	q.push(x); q.push(y);
	marc[x][y] = 1;
	if(p[x][y] == 3) {
		return;
	}
	while(!q.empty()) {
		int curx = q.front(); q.pop();
		int cury = q.front(); q.pop(); 
		//printf(" curx = %d, cury = %d\n",curx,cury);
		for(int i = 0; i < 4; i++) {
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if(marc[nx][ny] == 1 || p[nx][ny] == 0) continue;
			else {
				q.push(nx);
				q.push(ny);
				marc[nx][ny] = 1;
				dist[nx][ny] = dist[curx][cury] + 1;
			}
		}
	}
	return;
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%d",&p[i][j]);
			//fprintf(stderr, "p[%d][%d] = %d\n",i,j,p[i][j]);
		}
	}
	int x3=0, y3=0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(p[i][j] == 2) grid(i,j);
			if(p[i][j] == 3) {
				x3 = i; y3 = j;
			}
		}
	}
	
	printf("%d\n",dist[x3][y3] + 1);
}