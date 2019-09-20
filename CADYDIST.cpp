// REARRANJO – CADYDIST (SPOJ)
// Made on: 26/08/2019

#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

const int MAXN = 1e5 + 10;
int n;
long long int ans, a[MAXN], b[MAXN];

int main() {
	while(true) {
		ans = n = 0;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));

		scanf("%d", &n);
		if(n == 0) break;

		for(int i = 0; i < n; i++) {
			scanf("%lld", &a[i]);
		}
		for(int i = 0; i < n; i++) {
			scanf("%lld", &b[i]);
		}

		sort(a, a + n); sort(b, b + n);

		for(int i = 0; i < n; i++) {
			ans += a[i] * b[n-i-1];
		}

		printf("%lld\n", ans);
	}
}
