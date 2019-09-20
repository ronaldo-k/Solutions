// IDEIA DE MARCAÇÃO DE SOMA – Segredo do Cofre (OBI)
// Link: https://olimpiada.ic.unicamp.br/pratique/p1/2017/f1/cofre/

/* CASOS DE TESTE:
2 1
1 2
1

=> 0 1 1 0 0 0 0 0 0 0

4 2
1 2 3 4
1 3

=> 0 1 1 1 0 0 0 0 0 0

4 3
1 2 3 4
1 3 2

=> 0 1 2 1 0 0 0 0 0 0

4 4
1 2 3 4
1 4 2 3

=> 0 1 2 3 1 0 0 0 0 0

14 5
9 4 3 9 1 2 4 5 1 1 9 7 0 5
1 9 4 11 13

=> 1 6 3 1 4 3 0 1 0 4

5 4
5 8 0 5 1
1 4 2 5

=> 3 1 0 0 0 3 0 0 2 0
*/

#include <stdio.h>

#define debug(args...) fprintf(stderr, args)

const int MAXN = 2e5;
int n, m, bar[MAXN], resp[MAXN], pass[MAXN];

int main() {
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; i++) {
		scanf("%d", &bar[i]);
	}

	int lastpos = 0;
	for(int i = 1; i <= m; i++) {
		int ta;
		scanf("%d", &ta);

		if(ta > lastpos) {
			pass[ta+1]--; pass[lastpos+1]++;
		}
	 	else {
		 	pass[ta]++; pass[lastpos]--;
		}
		lastpos = ta;

		// for(int j = 1; j <= n; j++) {
		// 	printf("%d ", pass[j]);
		// }
		// printf("\n");
	}

	int cursum = 0;
	for(int i = 1; i <= n; i++) {
		resp[bar[i]] += pass[i] + cursum;
		cursum += pass[i];
	}

	for(int i = 0; i < 10; i++) {
		printf("%d ", resp[i]);
	}
	printf("\n");
}
