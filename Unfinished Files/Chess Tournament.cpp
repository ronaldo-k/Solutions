#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAXN = 5e5 + 10;

bool isConsistent = true;
int n, m, amt, rep[MAXN], dpt[MAXN], mrk[MAXN], inDeg[MAXN];

vector < int > g[MAXN], w[MAXN];
queue < int > q;

int find(int a) {
	if(a == rep[a]) return a;
	else return rep[a] = find(rep[a]);
}

void join(int a, int b) {
	a = find(a);
	b = find(b);

	if(a == b) return;

	if(dpt[a] > dpt[b]) {
		rep[b] = a;
		return;
	}
	rep[a] = b;

	if(dpt[a] == dpt[b]) {
		dpt[b]++;
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++) {
		rep[i] = i;
		dpt[i] = 0;
	}

	for(int i = 0; i < m; i++) {
		char tc; int ta, tb, tw;
		scanf("%d %c %d", &ta, &tc, &tb);

		if(tc == '=') {
			join(ta, tb); tw = 0;
		}
		else tw = 1;
		g[ta].push_back(tb);
		w[ta].push_back(tw);
		inDeg[tb]++;
	}

	for(int i = 0; i < n; i++) {
		if(inDeg[i] == 0) {
			mrk[i] = 1; q.push(i);
		}
	}

	while(!q.empty()) {
		int cur = q.front(); q.pop();
		debug("cur = %d\n", cur);

		for(int i = 0; i < g[cur].size(); i++) {
			int ngb = g[cur][i];
			inDeg[ngb]--;
			if(mrk[ngb] == 0 && inDeg[ngb] == 0) {
				mrk[ngb] = 1;
				q.push(ngb);
			}
		}
	}

	for(int i = 0; i < n; i++) {
		debug("%d (%d): ", i, mrk[i]);

		for(int j = 0; j < g[i].size(); j++) {
			int ngb = g[i][j], nw = w[i][j];
			if(mrk[ngb] == 0) {
				debug("%d ", ngb);
				amt++;
			}
		}
		debug("\n");
	}

	if(amt > 2) isConsistent = false;

	printf( (isConsistent) ? ("consistent\n") : ("inconsistent\n") );
}
