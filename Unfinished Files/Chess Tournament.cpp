#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAXN = 5e5 + 10;

int n, m, fat[MAXN], dpt[MAXN], mrk[MAXN], inDeg[MAXN];

vector < int > g[MAXN];
queue < int > q;

int find(int a) {
	if(a == fat[a]) return a;
	else return fat[a] = find(fat[a]);
}

void join(int a, int b) {
	a = find(a);
	b = find(b);

	if(a == b) return;

	if(dpt[a] > dpt[b]) {
		fat[b] = a;
		return;
	}
	fat[a] = b;

	if(dpt[a] == dpt[b]) {
		dpt[b]++;
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++) {
		fat[i] = i;
		dpt[i] = 0;
	}

	for(int i = 0; i < m; i++) {
		char tc; int ta, tb;
		scanf("%d %c %d", &ta, &tc, &tb);

		if(tc == '=') {
			join(ta, tb); continue;
		}
		g[tb].push_back(ta);
		inDeg[ta]++;
	}

	for(int i = 0; i < n; i++) {
		if(inDeg[i] == 0) {
			mrk[i] = 1; q.push(i);
		}
	}

	while(!q.empty()) {
		int cur = q.front(); q.pop();

		for(int i = 0; i < g[cur].size(); i++) {
			int ngb = g[cur][i]; ngb = fat[ngb];
			inDeg[ngb]--;
			if(mrk[ngb] == 0 && inDeg[ngb] == 0) {
				mrk[ngb] = mrk[cur] + 1;
				q.push(ngb);
			}
		}
	}

	for(int i = 0; i < n; i++) {
		debug("%d (%d): ", i, mrk[i]);

		for(int j = 0; j < g[i].size(); j++) {
			if(mrk[g[i][j]] == 0) debug("%d ", g[i][j]);
		}
		debug("\n");
	}
}
