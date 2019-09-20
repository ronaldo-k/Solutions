#include <stdio.h>
#include <algorithm>

using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAXN = 1e5 + 10;
int n, v[MAXN], c, ans;

int main() {
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}

	sort(v + 1, v + n + 1);

	for(int i = n; i >= 1; i--) {
		if(v[i] - c > i) {
			ans++;
		}
		else {
			c += v[i]; ans += v[i];
			break;
		}
	}

	printf("%d\n", ans);
}
