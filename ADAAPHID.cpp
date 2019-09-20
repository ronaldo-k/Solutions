// ADAAPHID
// Resolvido com Dynamic Segment Tree. Código de 12/04/19., em aula.
// Link do problema (SPOJ): https://www.spoj.com/problems/ADAAPHID/

#include <stdio.h>
#include <vector>

#define debug(args...) //fprintf(stderr, args)

using namespace std;

const long long int MAXN = 2e18;
long long int q, l;
vector < long long int > sum, e, d;

int create() {
	sum.push_back(0);
	e.push_back(-1);
	d.push_back(-1);

	return sum.size() - 1;
}

void update(long long int pos, long long int ini, long long int fim, long long int id, long long int val) {
	debug("UPDATE: pos = %lld, ini = %lld, fim = %lld, id = %lld, v = %lld\n", pos, ini, fim, id, val);

	if(id < ini || id > fim) return;
	if(ini == fim) {
		sum[pos] += val;
		return;
	}

	long long int m = (ini + fim) / 2;

	if(id <= m) {
		if(e[pos] == -1) {
			int aux = create();
			e[pos] = aux;
		}

		update(e[pos], ini, m, id, val);
	}
	else {
		if(d[pos] == -1) {
			int aux = create();
			d[pos] = aux;
		}

		update(d[pos], m+1, fim, id, val);
	}

	// Merge

	int sumE = (e[pos] == -1) ? 0 : sum[e[pos]];
	int sumD = (d[pos] == -1) ? 0 : sum[d[pos]];
	sum[pos] = sumE + sumD;
}

long long int query(long long int pos, long long int ini, long long int fim, long long int p, long long int q) {
	if(pos == -1) return 0;

	if(q < ini || p > fim) return 0;
	if(p <= ini && fim <= q) {
		return sum[pos];
	}

	long long int m = (ini + fim) / 2;

	return query(e[pos], ini, m, p, q) + query(d[pos], m+1, fim, p, q);
}

int main() {
	scanf("%lld", &q);
	create();

	for(int i = 0; i < q; i++) {
		long long int ta, tv;

		scanf("%lld %lld", &ta, &tv);

		long long int id = ta ^ l;
		long long int val = tv ^ l;

		update(0, 0, MAXN, id, val);

		l = query(0, 0, MAXN, 0, id);
		printf("%lld %lld\n", id, l);
	}
}
