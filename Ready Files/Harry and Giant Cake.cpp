// DP O(n) – Harry and Giant Cake (Taiwan ICPC Training Farm 20 - B)
// Problem ID: 210959-B
// Explanation in English

/*
Solution: Check solve() function (Line 22)

Time complexity: O(n)
Memory complexity: O(n)
*/

#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXN = 1e6 + 10;

int n, k, v[MAXN];
long long int dp[MAXN];

void solve() {
	/* Solution:
	Storage:
	dp[n] stores the maximum sum of qualities from the pieces of cake are not
	eaten by Ginny.

	Recursion:
	dp[n] = max(The sequence of size K that ends in N is eaten:
				dp[i-k], or
				the sequence of size K that ends in N is not eaten:
				dp[i-1] + v[i])

	Bases:
	 - dp[0] = 0: It's impossible to eat any cake if there's no cake to be
	 eaten. Therefore, the quality stored in dp[0] must be equivalent to the
	 total sum of the qualities of zero cakes, that is, dp[0] = 0.
	*/

	dp[0] = 0;

	for(int i = 1; i < k; i++) {
		dp[i] = dp[i-1] + v[i];
	}

	for(int i = k; i <= n; i++) {
		dp[i] = max(dp[i-k], dp[i-1] + v[i]);
	}
}

int main() {
	scanf("%d %d", &n, &k);

	for(int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}

	solve();

	printf("%lld\n", dp[n]);
}
