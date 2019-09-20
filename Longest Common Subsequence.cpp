// Iterative DP – Longest Common Subsequence (UVa 10405)
// Made on: 07/07/2019
// Works only for sample cases

#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

const int MAXN = 1010;
int mSize, nSize, dp[MAXN][MAXN];
char m[MAXN], n[MAXN];

void solve() {
	/*
	Base (Implícita):
		> dp[0][j] = 0 (0 <= j <= nSize)
		> dp[i][0] = 0 (0 <= i <= mSize)
	Armazenamento:
		> dp[i][j] armazena o tamanho da LCS que utiliza elementos de m[1] a m[i-1], quando comparads com os elementos de n[1] a n[j-1].
	Escolhas:
		> Se o caractere i-1 da string m for igual ao caractere j-1 da string n,
		a nova LCS inclui o elemento m[i-1] = n[j-1].
		> Senao, a LCS máxima até agora termina em m[i-2] ou n[j-2];
	*/

	for(int i = 1; i <= mSize; i++) {
		for(int j = 1; j <= nSize; j++) {
			if(m[i-1] == n[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
}

int main() {
	while(scanf(" %s %s", m, n) != EOF) {
		mSize = strlen(m); nSize = strlen(n);

		memset(dp, 0, sizeof(dp));
		solve();

		printf("%d\n", dp[mSize][nSize]);
	}
}
