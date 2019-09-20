// LIS (n logn DP) – Sequencia de Onda (CodCad)
// Made on: 10/06/2019

#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAXN = 1e5 + 10, INF = 2e9;
int n, v[MAXN], dpi[MAXN], dpd[MAXN], lis[MAXN], lds[MAXN];

void makeBase() {
	dpi[0] = dpd[0] = -INF;

	for(int i = 1; i <= n; i++) {
		dpd[i] = dpi[i] = INF;
	}
}

void solveLIS() {
	for(int t = 1; t <= n; t++) {
		int idi = lower_bound(dpi, dpi + n, v[t]) - dpi;
		dpi[idi] = v[t];
		lis[t] = idi;
	}
}

void solveLDS() {
	for(int t = n; t >= 1; t--) {
		int idd = lower_bound(dpd, dpd + n, v[t]) - dpd;
		dpd[idd] = v[t];
		lds[t] = idd;
	}
}

int getAnswer() {
	int ans = 0;

	for(int i = 1; i <= n; i++) {
		ans = max(ans, ( min(lis[i], lds[i]) * 2 ) - 1);
	}
	return ans;
}

int main() {
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}

	makeBase();

	solveLIS();
	solveLDS();

	printf("%d\n", getAnswer());
}
