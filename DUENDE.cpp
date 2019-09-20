#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

const int MAXN = 100, INF = 2e9;
int n, m, g[MAXN][MAXN], marc[MAXN][MAXN], dist[MAXN][MAXN], resp = 10000;
int dx[4] = {  1, -1,  0,  0},
	dy[4] = {  0,  0,  1, -1};

pair < int, int > in;
vector < pair < int, int > > outs;

void bfs(int ax, int ay) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			dist[i][j] = INF;
			marc[i][j] = 0;
		}
	}

	queue < pair < int, int > > q;
	marc[ax][ay] = 1; dist[ax][ay] = 0;

	q.push( make_pair(ax, ay) );

	while(!q.empty()) {
		int curx = q.front().first, cury = q.front().second;
		q.pop();

		for(int i = 0; i < 4; i++) {
			int nx = curx + dx[i], ny = cury + dy[i];

			if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if(dist[nx][ny] <= dist[curx][cury] + 1) continue;
			if(g[nx][ny] != 2) {
				marc[nx][ny] = 1;
				dist[nx][ny] = dist[curx][cury] + 1;

				q.push( make_pair(nx, ny) );
			}
		}
	}
	return;
}

int main() {
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%d", &g[i][j]);

			if(g[i][j] == 3) in = make_pair(i, j);
			if(g[i][j] == 0) outs.push_back( make_pair(i, j) );
		}
	}

	bfs(in.first, in.second);

	for(int i = 0; i < outs.size(); i++) {
		resp = min(resp, dist[outs[i].first][outs[i].second]);
	}

	printf("%d\n", resp);
}
