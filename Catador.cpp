#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

const int MAXN = 2e5 + 10;

int n, m, t;
long long int resp;
int v[MAXN], bloco[MAXN], ini[MAXN], fim[MAXN], cte[MAXN];

int main() {
	scanf("%d %d", &n, &m);

	t = sqrt(n) + 1;
	for(int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		bloco[i] = i/t;
		ini[bloco[i]] = bloco[i] * t;
		fim[bloco[i]] = min(n-1, (bloco[i]+1)*t - 1);

		//fprintf(stderr, "bloco[%d] = %d, iniB = %d, fimB = %d\n", i, bloco[i], ini[bloco[i]], fim[bloco[i]]);
	}

	for(int i = 0; i < m; i++) {
		int ta;
		scanf("%d", &ta);
		ta--;

		int vjm = max(ta - (v[ta] - cte[bloco[ta]]), 0), vjp = min(ta + (v[ta] - cte[bloco[ta]]), n-1);

		if(v[ta] - cte[bloco[ta]] <= 0) continue;

		//fprintf(stderr, "vjm = %d, vjp = %d. cteM = %d, cteP = %d (v[%d] = %d)\n", vjm, vjp, cte[bloco[vjm]], cte[bloco[vjp]], ta, v[ta]);
		//fprintf(stderr ," > t = %d >>>> bloco[vjm] = %d, bloco[vjp] = %d\n", t, bloco[vjm], bloco[vjp]);

		for(int j = vjm; j <= min(fim[bloco[vjm]], vjp); j++) {
			//printf("1. ERA: v[%d] = %d, E: v = %d\n", j, v[j], v[j]-1);
			v[j]--;
		}

		if(bloco[vjm] != bloco[vjp]) {

			for(int j = max(ini[bloco[vjp]], vjm); j <= vjp; j++) {
				//printf("2. ERA: v[%d] = %d, E: v = %d\n", j, v[j], v[j]-1);
				v[j]--;
			}
			for(int j = bloco[vjm] + 1; j <= bloco[vjp] - 1; j++) {
				//printf("3. ERA: cte[bloco[[%d]] = %d, E: v = %d\n", j, cte[bloco[j]], cte[bloco[j]]+1);
				cte[j]++;
			}
		}
	}

	for(int i = 0; i < n; i++) {
		resp += max(v[i] - cte[bloco[i]], 0);
	}

	printf("%lld\n", resp);
}
