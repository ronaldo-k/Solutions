// DP O(n²) – Etiquetas (OBI 2019 P2 F3)
// Explicações em Português

#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXN = 1e4 + 10, INF = 2e9;

bool isSorted = true;
int n, k, c, ans;
int v[MAXN], s[MAXN], dp[MAXN][MAXN];

void solve() {
	/* Função solve():
	Armazenamento:
	dp[K][N] armazena a soma total dos números descobertos num intervalo de 1 a
	N, com K etiquetas coladas de maneira ótima.

	Recursão:
	dp[K][N] = max(Cola-se uma etiqueta que termina na posição n:
	 			   dp[K-1][N-C], ou
				   não cola-se uma etiqueta que termina na posição n:
				   dp[K][N-1] + v[N])

	Bases:
	 - dp[K][0] = -∞: É impossível que se cole uma etiqueta quando o intervalo
	 analisado (de 1 a i, 1 ≤ i ≤ N) tem tamanho 0.
	 - dp[0][j] = dp[0][j-1] + v[j]: Quando não há nenhuma etiqueta colada,
	 dp[0][j] é igual à somas parciais do intervalo [1, j].

	*/

	for(int i = 1; i <= k; i++) {
		dp[i][0] = -INF;
	}
	for(int j = 1; j <= n; j++) {
		dp[0][j] = dp[0][j-1] + v[j];
	}

	for(int i = 1; i <= k; i++) {
		for(int j = 1; j <= n; j++) {
			dp[i][j] = dp[i-1][j-c];

			if(j >= c) {
				dp[i][j] = max(dp[i-1][j-c], dp[i][j-1] + v[j]);
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &k, &c);

	for(int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
		if(i > 0 && v[i] < v[i-1]) isSorted = false;
	}

	/* 1ª Parcial (10 pts): Os números no vetor estão ordenados crescentemente.
	Solução: Como os valores estão ordenados, é sempre ideal colocar as etique-
	tas nos primeiros valores em posição (ou seja, nos menores valores).

	Complexidade em tempo: O(n)
	Complexidade em memória: O(n)

	Exemplo:

	Entrada:
	6 2 2
	1 2 3 4 5 6
	Saída:
	11
	*/

	if(isSorted) {
		for(int i = 1; i <= n; i++) {
			s[i] = s[i-1] + v[i];
		}

		printf("%d\n", s[n] - s[k*c]);
	}

	/* 2ª Parcial (10 pts): Largura das etiquetas C = 1.
	Solução: As etiquetas devem cobrir os menores valores possíveis, o que é
	possível de maneira gulosa. É possível ordenar o vetor e solucionar o pro-
	blema como na parcial acima.

	Complexidade em tempo: O(n·logn)
	Complexidade em memória: O(n)

	Exemplo:

	Entrada:
	7 3 1
	8 7 2 -3 -4 9 1
	Saída:
	26
	*/

	else if(c == 1) {
		sort(v+1, v+(n+1));

		for(int i = 1; i <= n; i++) {
			s[i] = s[i-1] + v[i];
		}

		printf("%d\n", s[n] - s[k*c]);
	}

	/* 3ª Parcial (20 pts): Quantidade de etiquetas K = 1.
	Solução: É ideal cobrir a substring (isto é, a subsequência contínua) com
	menor valor possível. Testam-se todas as posições possíveis para a etiqueta.

	Complexidade em tempo: O(n)
	Complexidade em memória: O(n)

	Exemplo:

	Entrada:
	6 1 3
	8 -9 2 4 -2 10
	Saída:
	16
	*/

	else if(k == 1) {
		ans = -INF;

		for(int i = 1; i <= n; i++) {
			s[i] = s[i-1] + v[i];
		}

		for(int i = c; i <= n; i++) {
			ans = max(ans, s[n] - s[i] + s[i-c]);
		}

		printf("%d\n", ans);
	}

	/* Solução completa: Nenhuma restrição adicional.
	Solução: Ver solução na função solve() (Linha 15).

	Complexidade em tempo: O(n²)
	Complexidade em memória: O(n²+n)

	Exemplo:

	Entrada:
	12 2 3
	1 22 4 -8 9 2 10 -1 5 5 32 -11

	Saída:
	58
	*/
	else {
		solve();

		printf("%d\n", dp[k][n]);
	}
}
