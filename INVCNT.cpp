// NUMERO DE INVERSOES COM MERGE SORT

#include <stdio.h>
#include <string.h>

#define debug(args...) //fprintf(stderr, args)

using namespace std;

const int MAXN = 2e5 + 10;

int n;
long long int resp;
int v[MAXN], aux[MAXN];

void mergeSort(int i, int j) {
	if(i == j) return;

	int m = (i + j) / 2;
	mergeSort(i, m); mergeSort(m + 1, j);

	int p = i, k = i, q = m + 1;

	while(p <= m && q <= j){
		if(v[p] < v[q]) {
			aux[k] = v[p];

			resp += q - m - 1;
			debug(" > %lld\n", resp);
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
		k++; p++;

		resp += q - m - 1;

		debug(" > %lld\n", resp);
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
	int teste;
	scanf("%d", &teste);

	for(int casos = 0; casos < teste; casos++) {
		resp = 0LL;

		memset(v, 0, sizeof(v));
		memset(aux, 0, sizeof(aux));

		scanf("%d", &n);

		for(int i = 1; i <= n; i++) {
			scanf("%d", &v[i]);
		}

		mergeSort(1, n);

		//debug("resp = %lld\n", resp);
		printf("%lld\n", resp);
	}
}
