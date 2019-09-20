// MATSUM
// Resolvido com BIT 2D. Código de 22/03/19, em aula.
// Link do problema (SPOJ): https://www.spoj.com/problems/MATSUM/

#include <bits/stdc++.h>

#define debugPrint(args...) fprintf(stderr, args)

using namespace std;

const int MAXN = 1030;

int n, teste;
int atual[MAXN][MAXN], BIT[MAXN][MAXN];

void update(int x, int y, int val) {
	int ysalvo = y;

	while(x <= n) {
		y = ysalvo;

		while(y <= n) {
			BIT[x][y] += val;
			y += y & -y;
		}

		x += x & -x;
	}
}

int query(int x, int y) {
	int ysalvo = y, resp = 0;

	while(x > 0) {
		y = ysalvo;

		while(y > 0) {
			resp += BIT[x][y];
			y -= y & -y;
		}

		x -= x & -x;
	}

	return resp;
}

int main() {
	scanf("%d", &teste);

	for(int casos = 0; casos < teste; casos++) {
		scanf("%d", &n);

		// Zerando as matrizes
		memset(BIT, 0, sizeof(BIT));
		memset(atual, 0, sizeof(atual));

		while(true) {
			char inOperacao[10];
			scanf(" %s", inOperacao);

			// "SET"
			int x1, y1, x2, y2;
			if(inOperacao[1] == 'E') {
				// tx nesse caso e o valor a ser inserido
				int diff;
				scanf("%d %d %d", &x1, &y1, &x2);
				x1++; y1++;

				diff = x2 - atual[x1][y1];
				atual[x1][y1] = x2;

				update(x1, y1, diff);
			}

			// "SUM"
			if(inOperacao[1] == 'U') {
				scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

				x1++; y1++; x2++; y2++;

				int x2y2 = query(x2, y2);
				int x1y2 = query(x1 - 1, y2);
				int x2y1 = query(x2, y1 - 1);
				int x1y1 = query(x1 - 1, y1 - 1);

				printf("%d\n", x2y2 - x1y2 - x2y1 + x1y1);
			}

			// "END"
			if(inOperacao[1] == 'N') {
				break;
			}
		}
	}
} 
