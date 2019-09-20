#include <stdio.h>

const int MAXN = 110;
int n, k, v[MAXN][MAXN], e[3][MAXN], ans[2]; bool already;

int mod(int a) {
	if(a < 0) return -a;
	return a;
}

bool delta(int dx, int dy, int x, int y, int w) {
	int dist = mod(dx - x) + mod(dy - y);

	if(dist == w) return true;
	return false;
}

int main() {
	scanf("%d %d", &n, &k);

	for(int i = 0; i < k; i++) {
		int ta, tb, tw;
		scanf("%d %d %d", &ta, &tb, &tw);

		e[0][i] = ta; e[1][i] = tb; e[2][i] = tw;
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int aux = 0;

			for(int g = 0; g < k; g++) {
				if( delta(e[0][g], e[1][g], i, j, e[2][g]) ) aux++;
			}

			if(aux == k) {
				if(already == true) {
					printf("-1 -1\n");
					return 0;
				}
				ans[0] = i; ans[1] = j;
				already = true;
			}
		}
	}

	printf("%d %d\n", ans[0], ans[1]);
}
