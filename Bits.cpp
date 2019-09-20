// DP Simples - Bits (OBI)

#include <stdio.h>
#include <algorithm>

const int MAXN = 2000;
const int MOD = 1000000007;
int dp[MAXN];
int n, k;

int pot(int a) {
	int resp = 1;
	while(a-- > 0) {
		resp = (2*resp) % MOD;
	}
	return resp;
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
