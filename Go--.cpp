#include <stdio.h>
#include <algorithm>

using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAXN = 510;
int n, p, pc[MAXN][MAXN][2], dpE[MAXN][MAXN], dp[MAXN][MAXN][2];

// DP armazena o tamanho do maior quadrado de peças pretas e brancas que termina em uma certa posição

void solve(int p) {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(pc[i][j][1-p] == 1) { debug("A\n");
				dp[i][j][p] = 0;
				continue;
			}
			else if(pc[i][j][p] == 1) { debug("B\n");
				dp[i][j][p] = 1;

			}
			if(dp[i-1][j][p] == dp[i][j-1][p]) { debug("C\n");
				int a = max(dp[i-1][j][p], 0);
				if(pc[i-a][j-a][1-p] != 1 && a > 0) dp[i][j][p]++;
			}
			else { debug("D\n");
				dp[i][j][p] = min(dp[i][j-1][p], dp[i-1][j][p]);
			}

			debug("SOLVE: i: %d, j: %d, p: %d\n", i, j, p);
			for(int g = 1; g <= n; g++) {
				for(int h = 1; h <= n; h++) {
					debug("%d ", dp[g][h][p]);
				}
				debug("\n");
			}
			debug("\n\n");
		}
	}
}

int main() {
	scanf("%d %d", &n, &p);

	for(int i = 0; i < p; i++) {
		int ta, tb;
		scanf("%d %d", &ta, &tb);
		pc[ta][tb][0] = 1;
		dp[ta][tb][0] = 1;
	}

	for(int i = 0; i < p; i++) {
		int ta, tb;
		scanf("%d %d", &ta, &tb);
		pc[ta][tb][1] = 1;
		dp[ta][tb][1] = 1;
	}

	solve(0);
	//solve(d, dpB, pb);
}
