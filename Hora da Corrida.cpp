// Hora da Corrida (Maratona de Programação 2019 - B)

#include <stdio.h>

using namespace std;

#define debug(args...) //fprintf(stderr, args)

const int MAXN = 20;
int n, m, ans[MAXN];
double pct[MAXN];

int main() {
	scanf("%d %d", &n, &m);

	for(int i = 1; i < 10; i++) {
		ans[i] = n * m * i;
		ans[i] += (ans[i] % 10 == 0) ? 0 : 10;
		debug("%d -> %d\n", i, ans[i]);
	}

	for(int i = 1; i < 9; i++) {
		printf("%d ", ans[i]/10);
	}
	printf("%d\n", ans[9]/10);
}
