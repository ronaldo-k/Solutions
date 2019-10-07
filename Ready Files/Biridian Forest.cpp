// BFS – Biridian Forest (Codeforces #192 (Div. 1) - B)

#include <stdio.h>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

const int MAXN = 1010, INF = 2e9;

struct breeder {
	int x, y, a;

	breeder(int tx = 0, int ty = 0, int ta = 0) {
		x = tx, y = ty, a = ta;
	}
};

int n, m, bx, by, ex, ey, ans;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int dst[MAXN][MAXN], mrk[MAXN][MAXN];
char v[MAXN][MAXN];

vector < struct breeder > b;

void bfs(int x, int y) {
	queue < pair < int, int > > q;
	mrk[x][y] = 1, dst[x][y] = 0;

	q.push(make_pair(x, y));

	while(!q.empty()) {
		int curx = q.front().first, cury = q.front().second;
		q.pop();

		for(int i = 0; i < 4; i++) {
			int nx = curx + dx[i], ny = cury + dy[i];

			if(mrk[nx][ny] == 1) continue;
			else if(nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
			else if(v[nx][ny] != 'T') {
				dst[nx][ny] = min(dst[nx][ny], dst[curx][cury] + 1);
				mrk[nx][ny] = 1;

				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			scanf(" %c", &v[i][j]);
			dst[i][j] = INF;

			// If v[i][j] is a number between 1 and 9
			if(v[i][j] >= '1' && v[i][j] <= '9') {
				int ta = v[i][j] - '0';
				b.push_back( breeder(i, j, ta) );
			}
			if(v[i][j] == 'S') {
				bx = i, by = j;
			}
			if(v[i][j] == 'E') {
				dst[i][j] = 0;
				ex = i, ey = j;
			}
		}
	}

	bfs(ex, ey);

	for(int i = 0; i < b.size(); i++) {
		int tx = b[i].x, ty = b[i].y, ta = b[i].a;

		if(dst[tx][ty] <= dst[bx][by]) ans += ta;
	}

	printf("%d\n", ans);
}
