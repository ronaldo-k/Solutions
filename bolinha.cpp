#include <stdio.h>

int max(int a, int b) {
	if(a > b) return a;
	else return b;
}

int n, xi, yi;
int m[100][100], marc[100][100], dist[100][100], m2[100][100];
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};

void grid(int x, int y) {
	//printf("x = %d | y = %d\n",x,y);
	m2[x][y] = 1;
	if(marc[x][y] == 0) {
		marc[x][y] = 1;
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(marc[nx][ny] == 1) { continue; }
			else if(nx < 0 || ny < 0 || nx >= n || ny >= n) { continue; }
			else if(m[nx][ny] >= m[x][y]) {
				dist[nx][ny] = dist[x][y] + 1;
				m2[nx][ny] = 1;
				grid(nx,ny);
			}
			else { continue; }
		}
	}
}

int main() {
	scanf("%d%d%d",&n,&xi,&yi);
	xi--;yi--;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d",&m[i][j]);
			m2[i][j] = 0;
			marc[i][j] = 0;
			dist[i][j] = -1;
		}
	}
	int resp = 0;
	grid(xi,yi);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			//printf("i = %d | j = %d | m = %d | marc = %d | m2 = %d\n",i,j,m[i][j],marc[i][j],m2[i][j]);
			if(m2[i][j] == 1) resp++;
		}
	}
	printf("%d\n",resp);
}