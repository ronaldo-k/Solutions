#include <stdio.h>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

#define debug(args...) //fprintf(stderr, args)

const int MAXN = 1e5 + 10;

int n, m, maxDeg, idMaxDeg;
int deg[MAXN], mrk[MAXN], dpt[MAXN], beg[MAXN];

vector < pair < int, int > > e;
vector < int > g[MAXN];
set < int > b[MAXN];

void dfs(int cur) {
	mrk[cur] = 1;

	for(int i = 0; i < g[cur].size(); i++) {
		int ngb = g[cur][i];

		if(mrk[ngb] == 0) {
			dpt[ngb] = dpt[cur] + 1;

			if(cur == idMaxDeg) beg[ngb] = ngb;
			else beg[ngb] = beg[cur];

			dfs(ngb);
		}
	}
}

int main() {
	e.resize(MAXN);

	scanf("%d", &n);

	for(int i = 1; i <= n - 1; i++) {
		int ta, tb;
		scanf("%d %d", &ta, &tb);

		g[ta].push_back(tb);
		g[tb].push_back(ta);
		deg[ta]++, deg[tb]++;
		e[i] = make_pair(ta, tb);

		if(deg[ta] > maxDeg)
			maxDeg = deg[ta], idMaxDeg = ta;
		if(deg[tb] > maxDeg)
			maxDeg = deg[tb], idMaxDeg = tb;
	}

	dfs(idMaxDeg);

	// for(int i = 1; i <= n; i++) {
	// 	debug("%d -> dpt: %d -> beg: %d\n", i, dpt[i], beg[i]);
	// }

	scanf("%d", &m);

	for(int i = 1; i <= m; i++) {
		int top, ta, tb;
		scanf("%d %d", &top, &ta);

		if(top == 1) {
			int cura = e[ta].first, curb = e[ta].second;

			if(dpt[cura] > dpt[curb]) swap(cura, curb);
			b[beg[curb]].erase(dpt[curb]);
		}
		if(top == 2) {
			int cura = e[ta].first, curb = e[ta].second;

			if(dpt[cura] > dpt[curb]) swap(cura, curb);
			b[beg[curb]].insert(dpt[curb]);
		}
		if(top == 3) {
			scanf("%d", &tb);

			if(ta == tb)
				printf("0\n");

			// When ta and tb are in different subtrees
			else if (beg[ta] != beg[tb]) {
				debug("Case 1\n");

				bool isValid = true;

				debug("ta = %d, beg[ta] = %d, dpt[ta] = %d\n", ta, beg[ta], dpt[ta]);
				debug("tb = %d, beg[tb] = %d, dpt[tb] = %d\n", tb, beg[tb], dpt[tb]);

				debug("size[ta] = %d\n", b[beg[ta]].size());
				debug("size[tb] = %d\n", b[beg[tb]].size());

				if( b[beg[ta]].upper_bound(dpt[ta]) != b[beg[ta]].begin() )
					isValid = false;
				if( b[beg[tb]].upper_bound(dpt[tb]) != b[beg[tb]].begin() )
					isValid = false;

				if(!isValid) printf("-1\n");
				else printf("%d\n", dpt[ta] + dpt[tb]);
			}
			else {
				debug("Case 2\n");
				int sb = beg[ta];

				if(dpt[ta] > dpt[tb]) swap(ta, tb);

				if(b[sb].upper_bound(dpt[ta]) == b[sb].lower_bound(dpt[tb]))
					printf("%d\n", dpt[tb] - dpt[ta]);
				else
					printf("-1\n");
			}
		}
	}
}
