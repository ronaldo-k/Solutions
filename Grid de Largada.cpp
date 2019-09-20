#include <stdio.h>
#include <string.h>

#define debug(args...) fprintf(stderr, args)

using namespace std;

const int MAXN = 100;
int n, v1[MAXN], v2[MAXN], v[MAXN], aux[MAXN], m[MAXN], resp;

void mergeSort(int i, int j) {
	if(i == j) return;

	int m = (i + j) / 2;
	mergeSort(i, m); mergeSort(m + 1, j);

	int p = i, k = i, q = m + 1;

	while(p <= m && q <= j) {
		if(v[p] < v[q]) {
			aux[k] = v[p];

			resp += q - m - 1;
			p++;
		}
		else {
			aux[k] = v[q];
			q++;
		}

		k++;
	}

	while(p <= m) {
		aux[k] = v[p];
		p++; k++;

		resp += q - m- 1;
	}

	while(q <= j) {
		aux[k] = v[q];
		q++; k++;
	}

	for(int ta = i; ta <= j; ta++) {
		v[ta] = aux[ta];
	}
}

int main() {
	while(scanf("%d", &n) != EOF) {
		memset(v1, 0, sizeof(v1));
		memset(v2, 0, sizeof(v2));
		memset(v, 0, sizeof(v));
		memset(m, 0, sizeof(m));
		memset(aux, 0, sizeof(aux));

		resp = 0;

		for(int i = 1; i <= n; i++) {
			scanf("%d", &v1[i]);

			m[v1[i]] = i;
		}

		// debug("v1: \n");
		// for(int i = 1; i <= n; i++) {
		// 	debug("[%d]", v1[i]);
		// }

		// debug("m: \n");
		// for(int i = 1; i <= n; i++) {
		// 	debug("[%d]", m[i]);
		// }

		for(int i = 1; i <= n; i++) {
			scanf("%d", &v2[i]);

			v[i] = m[v2[i]];
		}

		// debug("v: \n");
		// for(int i = 1; i <= n; i++) {
		// 	debug("[%d]", v[i]);
		// }

		mergeSort(1, n);

		printf("%d\n", resp);
	}
}
