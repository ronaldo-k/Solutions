#include <stdio.h>
#include <string.h>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

#define debug(args...) //fprintf(stderr, args)

const int MAXN = 1e5 + 10;

int n, fat[MAXN], dep[MAXN], mk[MAXN];
long long int siz[MAXN], ans = -1;
pair < int, int > in[MAXN];

int find(int a) {
	if(a == fat[a]) return a;
	else return fat[a] = find(fat[a]);
}

void join(int a, int b) {
	a = find(a); b = find(b);
	debug("BEF: a: %d s: %d | b: %d s: %d\n", a, siz[a], b, siz[b]);

	if(a == b) return;

	if(dep[a] > dep[b]) {
		fat[b] = a;
		siz[a] += siz[b];

		debug("AFT1: a: %d s: %d | b: %d s: %d\n", a, siz[a], b, siz[b]);

		return;
	}
	fat[a] = b;
	siz[b] += siz[a];

	if(dep[a] == dep[b]) {
		dep[b]++;
	}

	debug("AFT2: a: %d s: %d | b: %d s: %d\n", a, siz[a], b, siz[b]);
}

int main() {
	while(true) {
		ans = -1;
		memset(dep, 0, sizeof(dep));
		memset(siz, 0, sizeof(siz));
		memset(mk, 0, sizeof(mk));
		memset(in, 0, sizeof(in));

		scanf("%d", &n);
		if(n == 0) return 0;

		for(int i = 0; i < n; i++) {
			scanf("%d", &in[i].first);
			in[i].second = i;
		}

		for(int i = 0; i < n; i++) {
			fat[i] = i;
			dep[i] = 0;
			siz[i] = 1;
		}

		sort(in, in+n);

		for(int i = n-1; i >= 0; i--) {
			mk[in[i].second] = 1;

			if(mk[in[i].second+1] == 1) { debug("FC:\n");
				join(in[i].second+1, in[i].second);
			}
			if(mk[in[i].second-1] == 1) { debug("SC:\n");
				join(in[i].second-1, in[i].second);
			}

			ans = max(siz[find(in[i].second)] * in[i].first, ans);

			debug("%d: %d %d siz: %d\n", i, in[i].first, in[i].second, siz[in[i].second]);

			debug("ans: %d\n\n", ans);
		}

		printf("%lld\n", ans);
	}
}
