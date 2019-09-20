// DP simples - Little Thief Shi (Codeforces)

#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXN = 2e6;
int n, v[MAXN], dp[MAXN];

int main() {
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	dp[0] = v[0];
	dp[1] = max(v[1], v[0]);
	dp[2] = max(v[0], max(v[1], v[2]));
	for(int i = 3; i < n; i++) {
		dp[i] = max(dp[i-1], dp[i-3] + v[i]);
	}

	printf("%d\n", dp[n-1]);
}
