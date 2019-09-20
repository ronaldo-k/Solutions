#include <stdio.h>
#include <queue>
#include <utility>
#include <algorithm>
#include <string.h>

using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAXN = 10;
int n, m, gx, gy, bx, by, mk[MAXN][MAXN], blc[MAXN][MAXN], dst[MAXN][MAXN], no;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, ans = -1; // blc: Blocked (Blocked positions)
int pos[][2] = {
	2, 2,
	2, 4,
	2, 6,
	4, 2,
	4, 4,
	4, 6,
	6, 2,
	6, 4,
	6, 6
};

void printTable() {
	debug("TABLE:\n");

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			debug("%d ", blc[i][j]);
		}
		debug("\n");
	}
}

void bfs(int bi, int bj, int id) {
	debug(" -> BFS: %d %d (id: %d)\n Table for this id: \n", bi, bj, id);

	if(id == 4502) {
		printTable();
		return;
	}

	memset(mk, 0, sizeof(mk));
	memset(dst, 0, sizeof(dst));

	queue < pair < int, int > > q;

	q.push( make_pair(bi, bj) );
	mk[bi][bj] = 1;
	dst[bi][bj] = 0;

	while(!q.empty()) {
		pair < int, int > cur = q.front();
		int curx = cur.first, cury = cur.second;
		q.pop();

		if(curx == gx && cury == gy) {
			debug(" -> (GX,GY) REACHED FOR ID: %d\n", id);
		}

		mk[curx][cury] = 1;

		for(int k = 0; k < 4; k++) {
			int x = curx + dx[k], y = cury + dy[k];

			if(mk[x][y] == 1) continue;
			if(blc[x][y] == 1) continue;
			if(x > n || y > m || x <= 0 || y <= 0) continue;

			q.push( make_pair(x, y) );
			dst[x][y] = dst[curx][cury] + 1;
		}
	}

	debug(" -> dst[gx][gy] = %d\n", dst[gx][gy]);

	if(ans < dst[gx][gy]) {
		debug("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n!!! ANS UPDATED TO %d !!!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", dst[gx][gy]);
	}

	ans = max(ans, dst[gx][gy]);
}

void backtrack(int x, int y, int inc) {
	// Receives X and Y coordinates for current wardrobe

	inc++;
	int newX = pos[inc][0], newY = pos[inc][1];
	debug("\n\nBACKTRACKING: (old) %d %d, (inc) %d, (new) %d %d\n", x, y, inc, newX, newY);

	printTable();

	blc[x][y] = 1;

	if(newX > n-1 || newY > m-1) return;

	if(blc[x+1][y] == 0) {
		blc[x+1][y] = 1;
		debug("1.inc = %d marked %d %d as 1\n", inc, x+1, y);

		if(inc < 9) backtrack(newX, newY, inc);
		else bfs(bx, by, ++no);

		blc[x+1][y] = 0;
	}

	if(blc[x-1][y] == 0) {
		blc[x-1][y] = 1;
		debug("2.inc = %d marked %d %d as 1\n", inc, x-1, y);

		if(inc < 9) backtrack(newX, newY, inc);
		else bfs(bx, by, ++no);

		blc[x-1][y] = 0;
	}

	if(blc[x][y+1] == 0) {
		blc[x][y+1] = 1;
		debug("3.inc = %d marked %d %d as 1\n", inc, x, y+1);

		if(inc < 9) backtrack(newX, newY, inc);
		else bfs(bx, by, ++no);

		blc[x][y+1] = 0;
	}

	if(blc[x][y-1] == 0) {
		blc[x][y-1] = 1;
		debug("4.inc = %d marked %d %d as 1\n", inc, x, y-1);

		if(inc < 9) backtrack(newX, newY, inc);
		else bfs(bx, by, ++no);

		blc[x][y-1] = 0;
	}
}

int main() {
	scanf("%d %d %d %d %d %d", &n, &m, &bx, &by, &gx, &gy);

	backtrack(pos[0][0], pos[0][1], 0);

	printf("ans: %d\n", ans);
}
