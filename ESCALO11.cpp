// Ordenacao topologica - ESCALO11 (SPOJ)

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <string.h>

using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAXN = 1e5;
int n, m, inDeg[MAXN], marc[MAXN];
vector < int > g[MAXN], resp;
set < int > q;

int main() {
	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; i++) {
		int ta, tb;
		scanf("%d %d", &ta, &tb); //ta -> tb

		inDeg[tb]++;
		g[ta].push_back(tb);
	}

	for(int i = 0; i < n; i++) {
		if(inDeg[i] == 0) {
			marc[i] = 1;
			q.insert(i);
		}
	}

	while(!q.empty()) {
		int cur = *q.begin(); q.erase(cur);
		resp.push_back(cur);

		for(int i = 0; i < g[cur].size(); i++) {
			int ngb = g[cur][i];
			inDeg[ngb]--;

			if(inDeg[ngb] == 0 && marc[ngb] == 0) {
				marc[ngb] = 1;
				q.insert(ngb);
			}
		}
	}

	for(int i = 0; i < n; i++) {
		if(marc[i] == 0) {
			printf("*\n");
			return 0;
		}
	}

	for(int i = 0; i < resp.size(); i++) {
		printf("%d\n", resp[i]);
	}
}
