#include <stdio.h>

#define debug(args...) fprintf(stderr, args);
using namespace std;

const int MAXN = 5010;
int val, qtd[10], v[10] = {2, 5, 10, 20, 50, 100};
long long int dp[MAXN];

void solve() {
	dp[0] = 1;

	for(int i = 0; i < 6; i++) {
		for(int j = val; j > 0; j--) {

			for(int m = 1; m <= qtd[i]; m++) {
				if(m * v[i] <= j) dp[j] += dp[j - m * v[i]];
			}

		}
	}
}

int main() {
	scanf("%d", &val);

	for(int i = 0; i < 6; i++) {
		scanf("%d", &qtd[i]);
	}

	solve();

	printf("%lld\n", dp[val]);
}
