#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

const int MAXN = 200;
int n, md1, md2, tc, mrk[MAXN], dst[MAXN], fat[MAXN];
vector < int > g[MAXN];

void dfs(int cur) {
	mrk[cur] = 1;

	for(int i = 0; i < g[cur].size(); i++) {
		int ngb = g[cur][i];

		if(mrk[ngb] == 0) {
			mrk[ngb] = 1;
			dst[ngb] = dst[cur] + 1;
			fat[ngb] = cur;

			dfs(ngb);
		}
	}
}

int main() {
	while(true) {
		scanf("%d", &n);
		if(n == 0) break;
		
		md1 = md2 = 0;
		tc++;

		if(n == 1) {
			printf("Teste %d\n1\n\n", tc);
			continue;
		}

		memset(dst, 0, sizeof(dst));
		memset(mrk, 0, sizeof(mrk));
		memset(fat, 0, sizeof(fat));
		for(int i = 0; i <= n; i++) {
			g[i].clear();
		}

		for(int i = 1; i <= n-1; i++) {
			int ta, tb;
			scanf("%d %d", &ta, &tb);

			g[ta].push_back(tb);
			g[tb].push_back(ta);
		}

		fat[1] = 1;
		dfs(1);

		for(int i = 1; i <= n; i++) {
			if(dst[i] > dst[md1]) md1 = i;
		}

		memset(dst, 0, sizeof(dst));
		memset(mrk, 0, sizeof(mrk));
		memset(fat, 0, sizeof(fat));
		fat[md1] = md1;

		dfs(md1);

		for(int i = 1; i <= n; i++) {
			if(dst[i] > dst[md2]) md2 = i;
		}

		for(int i = 1; i <= (dst[md2]+1)/2; i++) {
			md2 = fat[md2];
		}

		printf("Teste %d\n%d\n\n", tc, md2);
	}
}
