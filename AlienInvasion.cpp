// DYNAMIC PROGRAMMING – Alien Invasion (Skopuł)
// Made on: 02/09/2019

#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXN = 1e6 + 10;
int n, v[MAXN];
long long int dp[MAXN], ans;

void solve() {
	dp[0] = 0;
	dp[1] = v[1];

	for(int i = 2; i <= n; i++) {
		dp[i] = max(dp[i-1], dp[i-2] + v[i]);
		ans = max(dp[i], ans);
	}
}

int main() {
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}

	solve();

	printf("%lld\n", ans);
}
