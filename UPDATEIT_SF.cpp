// IDEIA DE MARCAÇÃO DE SOMA - UPDATEIT (SPOJ)
// Link: https://www.spoj.com/problems/UPDATEIT/

#include <stdio.h>
#include <string.h>

#define debug(args...) fprintf(stderr, args)

const int MAXN = 2e4;
int t, n, u, q, v[MAXN], ssv[MAXN];

int main() {
	scanf("%d", &t);

	for(int z = 0; z < t; z++) {
		scanf("%d %d", &n, &u);
		memset(v, 0, sizeof(v));
		memset(ssv, 0, sizeof(v));

		for(int i = 0; i < u; i++) {
			int ta, tb, tw;

			scanf("%d %d %d", &ta, &tb, &tw);

			ssv[ta] += tw; ssv[tb+1] -= tw;
		}

		int cursum = 0;
		for(int i = 0; i < n; i++) {
			v[i] = cursum + ssv[i];
			cursum += ssv[i];
		}

		scanf("%d", &q);
		for(int i = 0; i < q; i++) {
			int ta;
			scanf("%d", &ta);

			printf("%d\n", v[ta]);
		}
	}
}
