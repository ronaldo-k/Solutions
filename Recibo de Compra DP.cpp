#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXN = 110, MAXK = 25;
int n, k, dp[MAXN][MAXK][MAXK];

// dp[SOMA][LAST][ID]

void solve() {
	dp[0][0][0] = 1;

	for(int i = 1; i <= n; i++) {
		for(int j = k; j >= 0; j--) {
			for(int l = k; l >= 0; l--) {
				dp[i][j][l] = dp[i][j][l+1];
				if(i >= l) dp[i][j][l] += dp[i-l][j+1][l+1];
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &k);

	solve();

	printf("%d\n", dp[n][k][k]);
}
