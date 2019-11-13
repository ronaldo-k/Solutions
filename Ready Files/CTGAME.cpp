// 2D HISTOGRAM - City Game (SPOJ CTGAME)

#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAXN = 1010;

char v[MAXN][MAXN], h[MAXN][MAXN], dpl[MAXN][MAXN], dpr[MAXN][MAXN];
int t, n, m, ans;

int main() {
	scanf("%d", &t);
	
	for(int z = 0; z < t; z++) {
		memset(v, 0, sizeof(v)); memset(h, 0, sizeof(h));
		memset(dpl, 0, sizeof(dpl)); memset(h, 0, sizeof(dpr));
		ans = -1;
		
		scanf("%d %d", &n, &m);
		
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				scanf(" %c", &v[i][j]);
			}
		}
		
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				if(v[i][j] == 'R') h[i][j] = 0;
				else h[i][j] = h[i-1][j] + 1;
			}
		}
		
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				dpl[i][j] = (h[i][j-1] < h[i][j]) ? j : dpl[i][j-1];
				if(v[i][j] == 'R') dpr[i][j] = 0;
			}

			for(int j = m; j > 0; j--) {
				dpr[i][j] = (h[i][j+1] < h[i][j]) ? j : dpr[i][j+1];
				if(v[i][j] == 'R') dpr[i][j] = 0;
			}
		}
		
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				ans = max(ans, (dpr[i][j] - dpl[i][j] + 1) * h[i][j]);
			}
		}
		
		printf("%d\n", ans*3);
	}
}
