#include <stdio.h>
#include <algorithm>

using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAXN = 1e5, INF = 2e9;
int n, v[MAXN], lis[MAXN], lds[MAXN], dpi[MAXN], dpd[MAXN];

void makeBase() {
	dpi[0] = dpd[0] = INF;

	for(int i = 1; i <= n; i++) {
		dpi[i] = dpd[i] = INF;
	}
}

void solveLIS() {
	for(int i = 1; i <= n; i++) {
		int id = lower_bound(dpi + 1, dpi + n + 1, v[i]) - dpi;
		dpi[id] = v[i];
		lis[i] = id;
	}
}

void solveLDS() {
	for(int i = n; i >= 1; i--) {
		int id = lower_bound(dpd + 1, dpd + n + 1, v[i]) - dpd;
		dpd[id] = v[i];
		lds[i] = id;
	}
}

int main() {
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}

	makeBase();
	solveLIS(); solveLDS();

	debug("DPI:\n");
	for(int i = 1; i <= n; i++) {
		debug("%d ", dpi[i]);
	}
	debug("\n");

	debug("DPD:\n");
	for(int i = 1; i <= n; i++) {
		debug("%d ", dpd[i]);
	}
	debug("\n");

	for(int i = 1; i <= n; i++) {
		int curVal = dpi[i] - dpd[n-i] - 1;
	}
}
