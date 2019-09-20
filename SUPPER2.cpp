#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

#define debug(args...) fprintf(stderr, args);

const int MAXN = 2e5, INF = 2e9;
int n, v[MAXN], dpd[MAXN], dpi[MAXN], lis[MAXN], lds[MAXN], dpl[MAXN], dpr[MAXN], ansv[MAXN], lisSize;

int main() {
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	// solveLIS();
	for(int i = 0; i <= n; i++) {
		dpi[i] = INF;
	}

	dpi[0] = 0;

	for(int i = 0; i < n; i++) {
		int id = lower_bound(dpi, dpi + n + 1, v[i]) - dpi;

		dpi[id] = v[i];
		lis[i] = id;

		lisSize = max(lisSize, id);
	}

	// solveLDS();
	dpd[0] = -INF;

	for(int i = 1; i <= n; i++) {
		dpd[i] = INF;
	}

	for(int i = n-1; i >= 0; i--) {
		v[i] *= -1;

		int id = lower_bound(dpd, dpd + n + 1, v[i]) - dpd;

		dpd[id] = v[i];
		lds[i] = id;
	}

	// getAnswer();
	int ls;
	vector < pair < int, int > > ans;
	ans.clear();

	for(int i = 0; i < n; i++) {
		if(lis[i] + lds[i] - 1 < lisSize) ansv[i] = 0;
		else ans.push_back(make_pair(-v[i], i));
	}

	for(int i = 0; i < ans.size(); i++) {
		if(i == 0) dpl[i] = ans[i].first;
   		else dpl[i] = max(dpl[i-1], ans[i].first);
	}

	for(int i = ans.size() - 1; i >= 0; i--) {
		if(i == ans.size() - 1) dpr[i] = ans[i].first;
		else dpr[i] = min(dpr[i-1], ans[i].first);
	}

	printf("%d\n", ans.size());

	sort(ans.begin(), ans.end());

	for(int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i].first);
	}

	printf("\n");
}
