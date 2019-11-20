#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAXN = 5e5 + 10;

bool isConsistent = true;
int n, m, amt, cnt, rep[MAXN], dpt[MAXN], mrk[MAXN], inDeg[MAXN], lay[MAXN];

vector < int > g[MAXN], g2[MAXN], w[MAXN];
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

void printData() {
	debug("---\nCALL %d:\n", ++cnt);
	debug("Reps: \n");
	for(int i = 0; i < n; i++) {
		debug("%d (%d): ", i, rep[i]);
		for(int j = 0; j < g[i].size(); j++) {
			int ngb = g[i][j];
			debug("%d (%d) ", ngb, rep[ngb]);
		}
		debug("\n");
	}
	
	debug("Degs:\n");
	for(int i = 0; i < n; i++) {
		debug("%d (%d): ", i, inDeg[i]);
		for(int j = 0; j < g[i].size(); j++) {
			int ngb = g[i][j];
			debug("%d (%d) ", ngb, inDeg[ngb]);
		}
		debug("\n");
	}
	
	debug("Mrks: \n");
	for(int i = 0; i < n; i++) {
		debug("%d (%d): ", i, mrk[i]);
		for(int j = 0; j < g[i].size(); j++) {
			int ngb = g[i][j];
			debug("%d (%d) ", ngb, mrk[ngb]);
		}
		debug("\n");
	}

	debug("Lays: \n");
	for(int i = 0; i < n; i++) {
		debug("%d (%d): ", i, mrk[i]);
		for(int j = 0; j < g[i].size(); j++) {
			int ngb = g[i][j];
			debug("%d (%d) ", ngb, lay[ngb]);
		}
		debug("\n");
	}
}

void printData2() {
	debug("G2: \n");
	for(int i = 0; i < n; i++) {
		debug("%d (%d): ", i, rep[i]);
		for(int j = 0; j < g2[i].size(); j++) {
			int ngb = g2[i][j];
			if(mrk[ngb] == 0) debug("%d (%d) ", ngb, rep[ngb]);
		}
		debug("\n");
	}
}

void dfs(int cur) {
	mrk[cur] = 1;
	
	for(int i = 0; i < g[cur].size(); i++) {
		int ngb = g[cur][i];
		
		if(mrk[ngb] != cur) {
			mrk[ngb] = cur;
			dfs(ngb);
		}
		else {
			isConsistent = false;
			return;
		}
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
		scanf("%d %c %d", &tb, &tc, &ta);

		if(tc == '=') {
			join(ta, tb);
			tw = 0;
		}
		else tw = 1;
		g[ta].push_back(tb);
		w[ta].push_back(tw);
		inDeg[tb]++;
	}
	
	//printData();
	
	for(int i = 0; i < n; i++) {
		if(inDeg[i] == 0) {
			q.push(i); mrk[i] = 1;
			lay[i] = 0;
		}
	}
	
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		
		for(int i = 0; i < g[cur].size(); i++) {
			int ngb = g[cur][i], nw = w[cur][i];
			
			debug("%d -> %d, w: %d\n", cur, ngb, nw);
			
			inDeg[ngb]--;
			if(inDeg[ngb] == 0 && mrk[ngb] == 0) {
				lay[ngb] = lay[cur] + nw;
				mrk[ngb] = 1;
				debug("pushed %d (lay[ngb] = %d)\n", ngb, lay[ngb]);
				q.push(ngb);
			}
			
			printData();
		}
	}
}

///////////////////////////////////////////////////////////////////////////////

/*
5 5
0 > 1
1 > 2
1 > 3
3 > 4
2 = 4

Consistent
*/

#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAXN = 5e5 + 10;

bool isConsistent = true;
int n, m, amt, cnt, rep[MAXN], dpt[MAXN], mrk[MAXN], inDeg[MAXN], lay[MAXN];

vector < int > g[MAXN], g2[MAXN], w[MAXN];
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

void printData() {
	debug("---\nCALL %d:\n", ++cnt);
	debug("Reps: \n");
	for(int i = 0; i < n; i++) {
		debug("%d (%d): ", i, rep[i]);
		for(int j = 0; j < g[i].size(); j++) {
			int ngb = g[i][j];
			if(mrk[ngb] == 0) debug("%d (%d) ", ngb, rep[ngb]);
		}
		debug("\n");
	}
	
	debug("Degs:\n");
	for(int i = 0; i < n; i++) {
		debug("%d (%d): ", i, inDeg[i]);
		for(int j = 0; j < g[i].size(); j++) {
			int ngb = g[i][j];
			if(mrk[ngb] == 0) debug("%d (%d) ", ngb, inDeg[ngb]);
		}
		debug("\n");
	}
	
	debug("Mrks: \n");
	for(int i = 0; i < n; i++) {
		debug("%d (%d): ", i, mrk[i]);
		for(int j = 0; j < g[i].size(); j++) {
			int ngb = g[i][j];
			debug("%d (%d) ", ngb, mrk[ngb]);
		}
		debug("\n");
	}

	debug("Lays: \n");
	for(int i = 0; i < n; i++) {
		debug("%d (%d): ", i, mrk[i]);
		for(int j = 0; j < g[i].size(); j++) {
			int ngb = g[i][j];
			debug("%d (%d) ", ngb, mrk[ngb]);
		}
		debug("\n");
	}
}

void printData2() {
	debug("G2: \n");
	for(int i = 0; i < n; i++) {
		debug("%d (%d): ", i, rep[i]);
		for(int j = 0; j < g2[i].size(); j++) {
			int ngb = g2[i][j];
			if(mrk[ngb] == 0) debug("%d (%d) ", ngb, rep[ngb]);
		}
		debug("\n");
	}
}

void dfs(int cur) {
	mrk[cur] = 1;
	
	for(int i = 0; i < g[cur].size(); i++) {
		int ngb = g[cur][i];
		
		if(mrk[ngb] != cur) {
			mrk[ngb] = cur;
			dfs(ngb);
		}
		else {
			isConsistent = false;
			return;
		}
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
		scanf("%d %c %d", &tb, &tc, &ta);

		if(tc == '=') {
			join(ta, tb);
			tw = 0;
		}
		else tw = 1;
		g[ta].push_back(tb);
		w[ta].push_back(tw);
		inDeg[tb]++;
	}
	
	//printData();
	
	for(int i = 0; i < n; i++) {
		if(inDeg[i] == 0) {
			q.push(i); mrk[i] = 1;
		}
	}
	
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		
		for(int i = 0; i < g[cur].size(); i++) {
			int ngb = g[cur][i], nw = w[cur][i];
			
			debug("%d -> %d, w: %d\n", cur, ngb, nw);
			
			inDeg[ngb]--;
			if(inDeg[ngb] == 0) {
				lay[ngb] = lay[cur] + nw;
				mrk[ngb] = 1;
				debug("pushed %d\n", ngb);
				q.push(ngb);
			}
			
			//printData();
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < g[i].size(); j++) {
			int ngb = g[i][j], nw = w[i][j];
			
			debug("%d(R: %d, L: %d) -> %d(R: %d, L: %d)\n", i, rep[i], lay[i], ngb, rep[ngb], lay[ngb]);
			
			if(nw == 0 && lay[i] != lay[ngb]) {
				isConsistent = false;
				break;
			}
			if(nw == 1 && rep[i] == rep[ngb]) {
				isConsistent = false;
				break;
			}
		}
		if(!isConsistent) break;
	}
	
	if(isConsistent) printf("consistent\n");
	else printf("inconsistent\n");
	
	printData();
	
//	memset(mrk, 0, sizeof(mrk));
//	
//	for(int i = 0; i < n; i++) {
//		dfs(i);
//		printf("ans = %d\n", isConsistent);
//	}
}
