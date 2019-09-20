#include <stdio.h>
#include <algorithm>

#define debug(args...) //fprintf(stderr, args)
using namespace std;

const int MAXN = 1e4;
int resp = 0, n, m, k;
char barco[MAXN][MAXN];
int tiros[MAXN][MAXN], marc[MAXN][MAXN];
int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};

int totPeca, totTiro;

void dfs(int x, int y) {
	if(marc[x][y] == 1) return;
	marc[x][y] = 1;

	if(tiros[x][y] == 1) {
		totTiro++;
	}

	totPeca++;

	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];

		if(marc[nx][ny] == 1) continue;
		if(nx <= 0 || ny <= 0 || nx > n || ny > m) continue;

		if(barco[nx][ny] == '#') {
			if(tiros[nx][ny] == 1) {
				totTiro++;
			}

			totPeca++;
			dfs(nx, ny);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			scanf(" %c", &barco[i][j]);
		}
	}

	scanf("%d", &k);

	for(int i = 0; i < k; i++) {
		int ta, tb;

		scanf("%d %d", &ta, &tb);

		tiros[ta][tb] = 1;
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			debug("%c ", barco[i][j]);
		}
		debug("\n");
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			debug("%d ", tiros[i][j]);
		}
		debug("\n");
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(barco[i][j] == '#' && marc[i][j] == 0) {
				totPeca = totTiro = 0;
				dfs(i,j);
				debug("totPeca = %d, totTiro = %d\n", totPeca, totTiro);
				if(totPeca == totTiro) resp++;
			}
		}
	}

	printf("%d\n", resp);
}
