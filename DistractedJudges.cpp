#include <stdio.h>

#define debug(args...) fprintf(stderr,args);

const int MAXN = 2e5;
int n, last;
int v[MAXN], dp[MAXN];

/* VARIAVEIS:
n: Numero de valores da

v[]: Vetor contendo os valores da entrada
dp[i]: Guarda se e possivel fazer uma lista em que v[i] e a quantidade de ele-
mentos abaixo de v[i]. Portanto:
	se v[i] == n - i, dp[i] = 1;
	senao dp[i] = 0;
*/

int main() {
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}

	last = n;
	for(int i = n; i > 1; i--) {
		debug("i = %d, v[i] = %d, last = %d\n", i, v[i], last);

		if(last - i == v[i]) {
			dp[i] = 1;
			last = i + 1;
			debug("dp[i] = 1\n")
		}
	}

	dp[n+1] = 1;
	for(int i = 1; i <= n+1; i++) {
		if(dp[i] == 1) printf("%d\n", i-1);
	}
}
