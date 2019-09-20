// DP 3D – Caesar's Legions (CodeForces – CF Round #89 Div. 2)
// Made on: 03/06/2019

#include <stdio.h>
#include <algorithm>

using namespace std;

#define debug(args...) //fprintf(stderr, args)

const int MAXN = 110, MOD = 1e8;
int n1, n2, k1, k2, dp[MAXN][MAXN][3];

void makeBase() {
	for(int i = 1; i <= min(k1, n1); i++) {
		dp[i][0][0] = 1;
	}
	for(int i = 1; i <= min(k2, n2); i++) {
		dp[0][i][1] = 1;
	}
}

void solve() {
	for(int i = 1; i <= n1; i++) {
		for(int j = 1; j <= n2; j++) {
			for(int g = 0; g <= 1; g++) {
				int curl = (g == 0) ? k1 : k2;
				for(int l = 1; l <= curl; l++) {
					//debug("i: %d | j: %d | g: %d | l = %d\n", i, j, g, l);
					if(l <= i && g == 0) {
						dp[i][j][g] = (dp[i-l][j][1-g] + dp[i][j][g]) % MOD;
					}
					else if(l <= j && g == 1) {
						dp[i][j][g] = (dp[i][j-l][1-g] + dp[i][j][g]) % MOD;
					}
				}
			}
		}
	}
}

int main() {
	scanf("%d %d %d %d", &n1, &n2, &k1, &k2);

	makeBase();
	solve();

	printf("%d\n", (dp[n1][n2][0] + dp[n1][n2][1]) % MOD);
}
