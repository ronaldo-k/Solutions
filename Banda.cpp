// TESTING ALL COMBINATIONS (O(n^3)) – Banda (OBI)
// Made on: 02/09/2019

#include <stdio.h>

const int MAXN = 110;
int n, m, v[MAXN][MAXN], e[MAXN][3], ans[5], maxVal;

int main() {
	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; i++) {
		int ta, tb, tw;
		scanf("%d %d %d", &ta, &tb, &tw);
		v[ta][tb] = tw;
		v[tb][ta] = tw;
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= n; k++) {
				int c1 = v[i][j], c2 = v[j][k], c3 = v[i][k];

				if(i != j && j != k && i != k && c1 + c2 + c3 >= maxVal) {
					ans[0] = i;
					ans[1] = j;
					ans[2] = k;

					maxVal = c1 + c2 + c3;
				}
			}
		}
	}

	for(int i = 0; i < 3; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
}
