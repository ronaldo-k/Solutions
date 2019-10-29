// 01-BFS IN GRID - Laser Phones (SPOJ JAN09 Silver MLASERP)

/*
Idea:
Everytime a mirror must be used, the direction of the laser beam is able to 
change. Else, it follows the same direction. Hence, we are able to find the
path with the least amount of turns (i.e. changes in direction) by using these
turns as weights in a graph: If the laser beam turns, the distance from the
beggining coordinate to the current one is equal to the distance to the last
coordinate before turning plus one.
*/

#include <stdio.h>
#include <deque>
#include <algorithm>

using namespace std;

const int MAXN = 110, INF = 2e9;

struct node {
	int x, y, d;
	
	node(int tx = 0, int ty = 0, int td = 0) {
		x = tx, y = ty, d = td;
	}
};

char v[MAXN][MAXN];

int n, m, bx, by, ex, ey;
int dst[MAXN][MAXN][6], dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

deque < struct node > q;

void bfs(int x0, int y0) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			for(int k = 0; k < 4; k++) {
				dst[i][j][k] = INF;
			}
		}
	}
	
	for(int k = 0; k < 4; k++) {
		q.push_front( node(x0, y0, k) );
		dst[x0][y0][k] = 0;
	}
	
	while(!q.empty()) {
		int curx = q.front().x, cury = q.front().y, curd = q.front().d;
		
		q.pop_front();
		
		for(int k = 0; k < 4; k++) {
			int nx = curx + dx[k], ny = cury + dy[k]; // nd = k
			
			if(v[nx][ny] == '*') continue;
			if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if(dst[nx][ny][k] > dst[curx][cury][curd] && k == curd) {
				dst[nx][ny][k] = min(dst[curx][cury][k], dst[nx][ny][k]);
				q.push_front( node(nx, ny, k) );
			}
			if(dst[nx][ny][k] > dst[curx][cury][curd] + 1 && k != curd) {
				dst[nx][ny][k] = min(dst[curx][cury][curd] + 1, dst[nx][ny][k]);
				q.push_back( node(nx, ny, k) );
			}
		}
	}

}

int main() {
	bx = by = -1;
	
	scanf("%d %d", &m, &n);
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf(" %c", &v[i][j]);
			
			if(v[i][j] == 'C' && bx == -1) {
				bx = i, by = j;
				v[i][j] = '.';
			}
			else if(v[i][j] == 'C') {
				ex = i, ey = j;
				v[i][j] = '.';
			}
		}
	}
	
	bfs(bx, by);

	int ans = INF;
	for(int k = 0; k < 4; k++) {
		ans = min(ans, dst[ex][ey][k]);
	}
	printf("%d\n", ans);
}
