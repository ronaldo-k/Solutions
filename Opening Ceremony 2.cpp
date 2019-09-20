#include <stdio.h>
#include <algorithm>

using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAXN = 1e5 + 10, INF = 2e9;
int n, v[MAXN], ans = INF;

int main() {
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}

	sort(v, v + n + 1);

	for(int i = 0; i <= n; i++) {
		ans = min(ans, v[i] + n - i);
	}

	printf("%d\n", ans);
}
