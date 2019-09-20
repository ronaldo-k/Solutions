#include <stdio.h>
#include <set>
#include <utility>
#include <queue>

#define debug(args...) fprintf(stderr, args)

using namespace std;

const int MAXN = 2000;
int n, m, v[MAXN][MAXN], marc[MAXN][MAXN], depth[MAXN][MAXN];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int sx, sy, ex, ey, resp = 1;
set < pair < int, int > > path;

void search(int x, int y) {
	bool fail = true;
	marc[x][y] = 1;

	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];

		if(marc[nx][ny] == 1) continue;
		if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

		else if(v[nx][ny] == 2) {
			fail = false;
			depth[nx][ny] = depth[x][y] + 1;
			resp++;
			return;
		}
		else if(v[nx][ny] == 1) {
			fail = false;
			depth[nx][ny] = depth[x][y] + 1;
			resp++;
			search(nx, ny);
		}
	}
	if(fail == true) resp -= depth[x][y];
}

int main() {
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%d", &v[i][j]);

			if(v[i][j] == 2) {
				sx = i; sy = j;
			}
			else if(v[i][j] == 3) {
				ex = i; ey = j;
			}
		}
	}

	search(ex, ey);

	// for(int i = 0; i < n; i++) {
	// 	for(int j = 0; j < m; j++) {
	// 		debug("%d ", depth[i][j]);
	// 	}
	// 	debug("\n");
	// }

	// for(int i = 0; i < n; i++) {
	// 	for(int j = 0; j < m; j++) {
	// 		debug("%d ", marc[i][j]);
	// 	}
	// 	debug("\n");
	// }

	printf("%d\n", resp);
	//printf("or %d\n", (int)path.size());
}
