#include <stdio.h>

const int maxn = 1010;
int n, pl, pc, a, b;
int sl[maxn], sc[maxn];
int m[maxn][maxn];

int main() {
	scanf("%d",&n);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%d",&m[i][j]);
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			sl[j] += m[i][j];
			sc[i] += m[i][j]; //!
		}
	}

	printf("\n");
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(sc[i] + sl[j]  - (2*m[i][j]) > pc + pl - (2*m[a][b])) {
				pc = sc[i]; pl = sl[j]; a = i; b = j;
			}
		}
	}
	printf("%d",pl + pc - (2*m[a][b]));
}