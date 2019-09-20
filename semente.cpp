#include <stdio.h>
#include <algorithm>

#define debug(args...) //fprintf(stderr, args)

using namespace std;

const int MAXN = 2e6, INF = 2e9;
int f, r, d[MAXN], m[MAXN];

int main() {
	scanf("%d %d", &f, &r);

	for(int i = 1; i <= f; i++) {
		d[i] = INF;
	}

	for(int i = 1; i <= r; i++) {
		int ta;
		scanf("%d", &ta);
		m[ta] = 1;
	}

	int last = 0, maxd = -INF;

	for(int i = 1; i <= f; i++) {
		if(m[i] == 1) {
			d[i] = 0;
			last = i;
		}
		else if(last == 0) continue;
		else d[i] = i - last;
	}

	last = f + 1;
	for(int i = f; i >= 1; i--) {
		if(m[i] == 1) {
			d[i] = 0;
			last = i;
		}
		else if(last == f + 1) continue;
		else d[i] = min(d[i], last - i);
	}

	for(int i = 1; i <= f; i++) {
		debug("%d ", d[i]);
		maxd = max(maxd, d[i]);
	}
	debug("\n");

	printf("%d\n", maxd);
}
