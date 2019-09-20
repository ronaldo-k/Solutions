#include <stdio.h>
#include <algorithm>

#define debug(args...) //fprintf(stderr, args)

using namespace std;

const int MAXN = 1e6;

int n;
long long int r;
int t[MAXN]; // Guarda a altura das arvores

bool test(long long int a) {
	int smlTree;
	long long int resp = 0LL;

	for(int i = 0; i < n; i++) {
		if(t[i] >= a) {
			smlTree = i;
			debug("smlTree = %d, height = %d\n", smlTree, t[smlTree]);
			break;
		}
	}

	for(int i = smlTree; i < n; i++) {
		resp += t[i] - a;
	}

	debug("resp = %lld | ", resp);
	if(resp >= r) return true;
	else return false;
}

int main() {
	scanf("%d %lld", &n, &r);
	for(int i = 0; i < n; i++) {
		scanf("%d", &t[i]);
	}

	sort(t, t+n);

	int ini = 0, fim = t[n-1];

	if( !(test(ini)) ) return 0;

	while(ini < fim) {
		int m = (ini+fim) / 2;
		debug("ini = %d, fim = %d, m = %d\n", ini, fim, m);
		if(ini == fim - 1) m = fim;
		if(test(m)) ini = m;
		else fim = m - 1;
	}

	printf("%d\n", fim);
}
