// ACTIVITY SELECTION – FOCO (SPOJ)
// Made on: 26/08/2019

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

const int MAXN  = 1e6 + 10, INF = 2e9;

struct event {
	int b, e;

	bool operator<(struct event a) const {
		if(e == a.e) return b < a.b;
		return e < a.e;
	}
};

vector < struct event > v;

int n, last = -INF, ans;

int main() {
	while(scanf("%d", &n) != EOF) {
		last = -INF; ans = 0;
		v.clear();

		for(int i = 0; i < n; i++) {
			struct event ta;
			scanf("%d %d", &ta.b, &ta.e);
			v.push_back(ta);
		}

		sort(v.begin(), v.end());

		for(int i = 0; i < n; i++) {
			if(last < v[i].b) {
				last = v[i].e;
				ans++;
			}
		}

		printf("%d\n", ans);
	}
}
