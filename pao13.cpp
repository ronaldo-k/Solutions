#include <stdio.h>
#include <algorithm>

#define debug(args...) fprintf(stderr, args)

using namespace std;

const int MAXN = 1e5;

int n, k, v[MAXN]; // Comprimento dos paes

bool test(int m) {
	if(m == 0) return true;
	int div = 0;
	for(int i = 0; i < k; i++) {
		div += (v[i] / m);
	}

	debug("div = %d, k = %d\n", div, k);
	if(div >= k) return true;
	else return false;
}

int main() {
	scanf("%d %d", &n, &k);

	for(int i = 0; i < k; i++) {
		scanf("%d", &v[i]);
	}

	sort(v, v + n);

	int ini = 0, fim = 1e4;

	if( !(test(ini)) ) return 0;

	while(ini < fim) {
		int m = (ini + fim) / 2;
		debug("m = %d\n", m);

		if(ini == fim - 1) m = fim;
		if(test(m)) ini = m;
		else fim = m - 1;
	}

	printf("%d\n", fim);
}
