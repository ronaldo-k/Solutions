// DP – Transporte de Painéis Solares (URI)
// Made on: 17/06/2019

#include <stdio.h>
#include <algorithm>
#include <string.h>

#define debug(args...) //fprintf(stderr, args)

using namespace std;

const int MAXN = 110, INF = 2e9;
int n, k, f, v[MAXN], sv[MAXN], dp[MAXN][MAXN], call, cases;

// void debugDP() {
// 	call++;
// 	printf("call %d:\n",call);
// 	for(int i = 0; i <= n; i++) {
// 		for(int j = 0; j <= k; j++) {
// 			printf("%d ", dp[i][j]);
// 		}
// 		printf("\n");
// 	}
// 	printf("\n");
// }

void makeBase() {
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= k; j++) {
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
}

void solve() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= k; j++) {
			for(int l = 0; l <= i; l++) {
				dp[i][j] = min( dp[i][j], max(dp[l][j-1], sv[i] - sv[l]) );

				debug("i:%d j:%d l:%d\n", i, j, l);
				//debugDP();
			}
		}
	}
}

void getAnswer() {
	int ans = dp[n][k];

	printf("%d $%d\n", ans, ans * k * f);
}

int main() {
	scanf("%d", &cases);
	for(int t = 0; t < cases; t++) {
		memset(v, 0, sizeof(v));
		memset(sv, 0, sizeof(sv));
		memset(dp, 0, sizeof(dp));

		scanf("%d %d %d", &n, &k, &f);

		for(int i = 1; i <= n; i++) {
			scanf("%d", &v[i]);
			sv[i] = sv[i-1] + v[i];
		}

		makeBase();
		solve();
		//debugDP();
		getAnswer();
	}
}
