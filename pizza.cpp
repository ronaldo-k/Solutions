#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 10;
int n, v[MAXN], sum[MAXN], kad[MAXN];

int main() {
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);

		if(i == 1)
			sum[i] = v[i],
			kad[i] = max(v[i], 0);
		else
			sum[i] = v[i] + sum[i-1],
			kad[i] = max(kad[i-1] + v[i], 0);
	}

	int ans = 0;

	for(int i = 1; i <= n; i++) {
		ans = max( ans, kad[i] + (sum[n] - sum[i]) );
	}

	int tv = 0;

	for(int i = 1; i <= n; i++) {
		tv = max(0, tv + v[i]);
		ans = max(ans, tv);
	}

	printf("%d\n", ans);
}
