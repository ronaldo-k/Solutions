#include <stdio.h>
#include <string.h>

#define debug(args...) fprintf(stderr, args)

using namespace std;

const int MAXN = 35;
int n;
long long int dp[MAXN][MAXN];

void makeBase() {
	dp[1][1] = 1; dp[1][0] = 1;
}

void solve() {
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= 2; j++) {
			for(int l = 1; l <= 2; l++) {
				if(i >= l) dp[i][j] += dp[i-l][j-1];
			}
		}
	}
}

int main() {
	while(true) {
		memset(dp, 0, sizeof(dp));

		scanf("%d", &n);
		if(n == 0) break;

		makeBase();
		solve();

		printf("%lld\n", (1 << n) - (dp[n][0] + dp[n][1] + dp[n][2]));
	}
}
