#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 10;
int n, m;

vector < int > dp[MAXN], v[MAXN], vv, dpv;

int main() {
	while(true) {
		scanf("%d %d", &m, &n);

		if(m == 0 && n == 0) {
			return 0;
		}

		for(int i = 1; i <= m; i++) {
			v[i].clear();
			dp[i].clear();

			v[i].resize(n + 10);
			dp[i].resize(n + 10);
		}
		vv.clear();
		dpv.clear();

		dpv.resize(m + 10);

		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= n; j++) {
				int ta;
				scanf("%d", &ta);

				v[i][j] = ta;
			}
		}

		for(int i = 1; i <= m; i++) {
			for(int j = 0; j <= n; j++) {
				if(j == 0) {
					dp[i][j] = 0;
					continue;
				}

				if(j == 1) {
					dp[i][j] = v[i][j];
					continue;
				}

				dp[i][j] = max(dp[i][j-1], v[i][j] + dp[i][j-2]);
			}
		}

		dpv.clear();

		dpv.push_back(0);
		vv.push_back(0);
		for(int i = 1; i <= m; i++) {
			vv.push_back(dp[i][n]);
		}

		dpv.push_back(vv[1]);

		for(int i = 2; i <= m; i++) {
			dpv[i] = max(dpv[i-1], vv[i] + dpv[i-2]);
		}

		printf("%d\n", dpv[m]);
	}
}
