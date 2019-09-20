// ACTIVITY SELECTION – JDENTIST (SPOJ)
// Made on: 26/08/2019

#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 10, INF = 2e9;

struct event {
	int b, e;

	bool operator<(struct event a) const {
		if(e == a.e) return b < a.b;
		return e < a.e;
	}
} v[MAXN];

int n, last = -INF, ans;

int main() {
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		scanf("%d %d", &v[i].b, &v[i].e);
	}

	sort(v, v + n);

	for(int i = 0; i < n; i++) {
		if(last <= v[i].b) {
			last = v[i].e;
			ans++;
		}
	}

	printf("%d\n", ans);
}
