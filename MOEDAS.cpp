#include <stdio.h>

const int MAXN = 6e4, INF = 2e9;
int n, m, v[MAXN], dp[MAXN];
int main() {
	while(true) {
		scanf("%d", &n);
		if(n == 0) break;
		scanf("%d", &m);

		for(int i = 1; i <= n; i++) dp[i] = INF;

		for(int i = 1; i <= m; i++) {
			scanf("%d", &v[i]);
		}

		dp[0] = 0;

		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= n; j++) {
				if(v[i] <= j && dp[j] > dp[j - v[i]]) dp[j] = 1 + dp[j - v[i]];
			}
		}

		if(dp[n] < INF) printf("%d\n", dp[n]);
		else printf("Impossivel\n");
	}
}
