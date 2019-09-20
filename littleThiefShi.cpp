#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAXN = 1e6 + 10;
int n, v[MAXN], dp[MAXN];

//---------------------------//

int main() {
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}

	dp[0] = 0;
	dp[1] = v[1];
	dp[2] = max(v[1], v[2]);

	for(int i = 3; i <= n; i++) {
		dp[i] = max( dp[i-1], v[i] + dp[i-3] );
	}

	printf("%d\n", dp[n]);
}
