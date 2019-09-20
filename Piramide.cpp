// DP ("Backtracking with Memorization" style) – Pirâmide (OBI 2018 F1 P1)
// Made on: 17/06/2019

#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXN = 110;
int n, in[MAXN][MAXN], sp[MAXN][MAXN], dp[MAXN][MAXN][MAXN];

int solve(int i, int j, int l) {
	if(dp[i][j][l] != 0) return dp[i][j][l];
	int ans = 0, ansL = 0, ansR = 0;

	if(l > 0) {
		ansL = solve(i, j-1, l-1);
		ansR = solve(i+1, j, l-1);
	}

	ans = min(ansL, ansR) + (sp[l][j] - sp[l][i-1]);
	dp[i][j][l] = ans;
	return ans;
}

int main() {
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%d", &in[i][j]);
			sp[i][j] = sp[i][j-1] + in[i][j];
		}
	}

	printf("%d\n", solve(1, n, n));
}
