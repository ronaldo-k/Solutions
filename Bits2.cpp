#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXN = 1010, MOD = 1e9 + 7;
int n, k, dp[MAXN];

int pot(int a) {
	int ans = 1;
	for(int i = 1; i <= a; i++) {
		ans = (2 * ans) % MOD;
	}
	return ans;
}

int main() {
	scanf("%d %d", &n, &k);

	for(int i = 1; i <= n; i++) {
		if(i < k) dp[i] = pot(i);
		else if(i == k) dp[i] = pot(i) - 1;
		else {
			dp[i] = 0;
			for(int j = 1; j <= k; j++) {
				dp[i] = (dp[i] + dp[i-j]) % MOD;
			}
		}
	}

	printf("%d\n", dp[n]);
}
