#include <stdio.h>
#include <algorithm>

const int MAXN = 110, MAXK = 20;
int v[MAXN], sv[MAXN],dp[MAXN][MAXK];

int main() {
	int casos;
	scanf("%d", &casos);

	for(int z = 0; z < casos; z++) {
		int n, k, frete;

		scanf("%d %d %d\n", &n, &k, &frete);
		for(int i = 1; i <= n; i++) {
			scanf("%d\n", &v[i]);
		}

		sv[i] = v[i];
		for (int i = 2; i <= n; i++) {
			sv[i] = sv[i-1] + v[i];
		}

		dp[0][0] = 0;
		for(int i = 1; i <= n; i++) {
			for(int c = 1; c <= k; c++) {
				for(int j = 1; j <= i; j++) {
					dp[i][c] = min( max( dp[j-1][c-1], sv[i] - sv[i-1] ) );
				}
			}
		}

		printf("%d $%d", dp[n][k], dp[n][k]*k*frete);
	}
}
