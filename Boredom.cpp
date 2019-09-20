// SIMPLE DP - Boredom (Codeforces) – 455A
// Made on: 27/05/2019

#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 10;
long long int n, m[MAXN], dp[MAXN];

int main() {
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		int ta;
		scanf("%lld", &ta);
		m[ta]++;
	}

	dp[0] = m[0];
	dp[1] = max(m[1], m[0]);

	for(int i = 2; i < MAXN; i++) {
		dp[i] = max(dp[i-1], dp[i-2] + m[i]*i);
	}

	printf("%lld\n", dp[MAXN-1]);
}
