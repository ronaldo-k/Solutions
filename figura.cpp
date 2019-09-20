#include <stdio.h>

const int MAXN = 110;
int n, c, m, imp[MAXN], marc[MAXN], resp;

int main() {
	scanf("%d %d %d", &n, &c, &m);

	for(int i = 1; i <= c; i++) {
		int ta;
		scanf("%d", &ta);

		imp[ta] = 1;
	}
	for(int i = 1; i <= m; i++) {
		int ta;
		scanf("%d", &ta);

		marc[ta] = 1;
	}

	for(int i = 1; i <= n; i++) {
		if(imp[i] == 1 && marc[i] == 0) resp++;
	}

	printf("%d\n", resp);
}
