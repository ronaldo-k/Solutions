#include <stdio.h>
#include <algorithm>

#define debug(args...) //fprintf(stderr, args);

using namespace std;

const int MAXN = 2e5 + 10;

int sa, sb; // Tamanho dos vetores a e b;
int a[MAXN];

int binarySearch(int val) {
	int ini = 1, fim = sa;

	/*
	Busca binaria para descobrir a quantidade de posicoes entre o inicio do ve
	tor e o primeiro valor maior ou igual val.
	*/

	if(!(a[ini] <= val)) return 0;

	while(ini < fim) {
		int m = (ini + fim) / 2;
		if(ini == fim - 1) m = fim;
		debug("val = %d, m = %d, ini = %d, fim = %d, a[m] = %d\n", val, m, ini, fim, a[m]);

		if(a[m] <= val) ini = m;
		else fim = m - 1;
	}

	debug("ini = fim = %d\n", ini);
	return ini;
}

int main() {
	scanf("%d %d", &sa, &sb);

	for(int i = 1; i <= sa; i++) {
		scanf("%d", &a[i]);
	}

	sort(a, a + sa);

	for(int i = 0; i < sb; i++) {
		int ta;

		scanf("%d", &ta);

		printf("%d\n", binarySearch(ta));
	}
}
