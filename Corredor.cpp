// CLASSICAL DP (KADANE) – Corredor (OBI)
// Made on: 27/05/2019

#include <stdio.h>
#include <algorithm>

using namespace std;
const int MAXN = 6e4;
int n, v[MAXN], dp[MAXN], ans;

int main() {
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}

	dp[1] = max(0, v[1]);

	for(int i = 2; i <= n; i++){
		dp[i] = max(v[i], v[i] + dp[i-1]);
	}

	for(int i = 1; i <= n; i++) {
		ans = max(ans, dp[i]);
	}

	printf("%d\n", ans);
}
