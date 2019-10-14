// 01-BFS IN GRID – Chamber of Secrets (Codeforces Croc Champ 2012 - Round 1 B)
// There's also a solution that uses standard BFS.

#include <stdio.h>
#include <deque>

using namespace std;

const int MAXN = 1010, INF = 2e9;

char v[MAXN][MAXN];

int n, m;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int dst[MAXN][MAXN][4];

deque < int > q;

void bfs01(int inX, int inY, int inDir) {
	for(int a = 0; a < 4; a++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				dst[i][j][a] = INF;
			}
		}
	}

	dst[inX][inY][inDir] = 0;
	q.push_front(inX);	q.push_front(inY);
	q.push_front(inDir);

	while(!q.empty()){
		int d = q.front(); q.pop_front();
		int y = q.front(); q.pop_front();
		int x = q.front(); q.pop_front();

		if(v[x][y] == '.') {
			int nx = x + dx[d], ny = y + dy[d];
			if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			if(dst[nx][ny][d] > dst[x][y][d]) {
				dst[nx][ny][d] = min(dst[nx][ny][d], dst[x][y][d]);

				q.push_front(nx); q.push_front(ny);
				q.push_front(d);
			}

			continue;
		}

		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			if(d == i && dst[nx][ny][d] > dst[x][y][d]) {
				dst[nx][ny][d] = dst[x][y][d];

				q.push_front(nx); q.push_front(ny);
				q.push_front(d);

				continue;
			}

			if(dst[nx][ny][i] > dst[x][y][d] + 1) {
				dst[nx][ny][i] = dst[x][y][d] + 1;

				q.push_back(i);
				q.push_back(ny); q.push_back(nx);
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf(" %c", &v[i][j]);
		}
	}

	bfs01(n-1, m-1, 1);

	if(v[0][0] != '#') {
		if(dst[0][0][1] == INF) printf("-1\n");
		else printf("%d\n", dst[0][0][1]);

		return 0;
	}

	int mAns = INF, idAns = -1;
	for(int i = 0; i < 4; i++) {
		if(dst[0][0][i] < mAns) {
			mAns = dst[0][0][i];
			idAns = i;
		}
	}

	if(idAns == 1) printf("%d\n", mAns);
	else if(idAns != -1) printf("%d\n", mAns+1);
	else printf("-1\n");
}
