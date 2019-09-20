// DP 3D – Bar Codes (UVa – 10721)
// Made on: 03/06/2019

#include <stdio.h>
#include <string.h>

#define debug(args...) fprintf(stderr, args)

const int MAXN = 60;
int n, k, m;
long long int ans, dp[MAXN][MAXN][MAXN];;

void makeBase() {
	for(int i = 1; i <= m; i++) {
		dp[i][1][i] = 1;
	}
}

void solve() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= k; j++) {
			for(int g = 1; g <= m; g++) {
				for(int z = 1; z <= m; z++) {
					if(i - g >= z) dp[i][j][g] += dp[i-g][j-1][z];
					else break;
				}
			}
		}
	}
}

int main() {
	while(scanf("%d %d %d", &n, &k, &m) != EOF) {
		ans = 0;
		memset(dp, 0, sizeof(dp));

		makeBase();
		solve();

		for(int i = 1; i <= m; i++) {
			ans += dp[n][k][i];
		}

		printf("%lld\n", ans);
	}
}
