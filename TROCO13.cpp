// CLASSICAL DP (KNAPSACK) – TROCO13 (SPOJ)
// Made on: 27/05/2019

#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 10, INF = 2e9;
int n, k, m[MAXN], dp[MAXN];

int main() {
	scanf("%d %d", &n, &k);

	for(int i = 0; i < k; i++) {
		scanf("%d", &m[i]);
	}

	dp[0] = 1;

	for(int i = 0; i < k; i++) {
		for(int j = n; j > 0; j--) {
			dp[j] = dp[j] | dp[j-m[i]];
		}
	}

	printf("%c\n", (dp[n] != 0) ? 'S' : 'N');
}
