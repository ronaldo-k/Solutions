// BINARY SEARCH ON ANSWER — Comedores de Pipoca (Maratona de Programação 2019 - L) 

#include <stdio.h>
#include <algorithm>

using namespace std;

#define debug(args...) //fprintf(stderr, args)

const int MAXN = 1e5 + 10, MAXV = 1e9;
int n, m, k;
long long int ans, totSum, maxSum, v[MAXN];

bool test(long long int lim) {
	int id = 1;
	long long int val = 0;

	if(totSum > lim * k * m) return false;
	if(maxSum > lim * k) return false;

	for(int i = 1; i <= n; i++) {
		if(val + v[i] > lim*k)
			val = v[i], id++;
		else
			val += v[i];

		debug("val = %lld, id = %d, i = %d\n", val, id, i);
	}

	//if(val > lim*k)
	//	id++;

	debug("id = %d final pra lim = %lld\n", id, lim);

	if(id > m) return false;
	else return true;
}

int binarySearch() {
	int ini = 1, fim = MAXV;

	while(ini < fim) {
		int m = (ini + fim) / 2;

		debug("%d --- %d\n", ini, fim);

		if(!test(m)) {
			ini = m+1;
		}
		else {
			fim = m;
		}
	}

	return ini;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);

	for(int i = 1; i <= n; i++) {
		scanf("%lld", &v[i]);
		maxSum = max(maxSum, v[i]);
		totSum += v[i];
	}

	ans = binarySearch();

	printf("%lld\n", ans);
}
