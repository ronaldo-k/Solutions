// OLD

#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 2e5, INF = 2e9;
int n, v[MAXN], nv[MAXN], dpd[MAXN], dpi[MAXN], lis[MAXN], lds[MAXN];

void makeBase() {
	dpi[0] = dpd[0] = INF;
	for(int i = 1; i <= n; i++) {
		dpi[0] = dpd[0] = -INF;
	}
}

void solveLIS() {
	for(int i = 1; i <= n; i++) {
		int idi = lower_bound(dpi, dpi + n, v[i]) - dpi;

		dpi[idi] = v[i];
		lis[i] = idi;
	}
}

void solveLDS() {
	for(int i = 1; i <= n; i++) {
		int idd = lower_bound(dpd, dpd, + n, nv[i]) - dpd;

		dpd[idd] = nv[i];
		lds[i] = idd;
	}
}

void getAnswer() {
	int lissize = 0, lsb = 0;
	vector < int > ans;

	for(int i = 1; i <= n; i++) {
		lissize = max(lissize, lis[i] + lds[i] - 1);
		if(lissize > lsb) {
			ans.clear();
			ans.push_back(i);
		}
		lsb = lissize;
	}

	int vs = ans.size();

	printf("%d\n", vs);
	for(int i = 0; i < vs; i++) {
		printf("%d ", v[i]);
	}

	printf("\n");
}

int main() {
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) {
		scanf("%d", v[i]);
		nv[i] = -v[i];
	}

	makeBase();

	solveLIS();
	solveLDS();

	getAnswer();
}
