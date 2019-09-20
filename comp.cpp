#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 2e3;
int n, m, inDeg[MAXN], outDeg[MAXN], type[MAXN], marc[MAXN], sow, fsum, dif[MAXN];
vector < int > g[MAXN], w[MAXN], cy;

void search(int a) {
	marc[a] = 1;

	for(int i = 0; i < g[a].size(); i++) {
		int ngb = g[a][i];

		if(marc[ngb] == 0) {
			if(type[ngb] == 0) fsum += w[a][i];
			marc[ngb] = 1;
			search(ngb);
		}
	}
}

int main() {
	scanf("%d %d", &m, &n);

	for(int i = 1; i <= m; i++) {
		int ta, tcost, tb;
		scanf("%d %d %d", &ta, &tcost, &tb);
		outDeg[ta]++; inDeg[tb]++;
		sow += tcost;
		dif[ta] -= tcost; dif[tb] -= tcost;

		g[ta].push_back(tb);
		w[ta].push_back(tcost);
	}

	queue < int > q;

	for(int i = 1; i <= n; i++) {
		if(inDeg[i] == 0 || outDeg[i] == 0) {
			type[i] = 1;
			q.push(i);
		}
	}

	while(!q.empty()) {
		int cur = q.front(); q.pop();

		for(int i = 0; i < g[cur].size(); i++) {
			int ngb = g[cur][i];
			inDeg[ngb]--;

			if(inDeg[ngb] == 0 && type[ngb] == 0) {
				type[ngb] = 1;
				q.push(i);
			}
		}
	}

	int cyStart = 0;
	bool bCycle = false;
	for(int i = 1; i <= n; i++) {
		if(type[i] == 1) {
			bCycle = false;
		}
		else {
			cyStart = i;
			bCycle = true;
			printf("S\n");
			break;
		}
	}
	if(!bCycle) printf("N\n");

	if(!bCycle) {
		printf("%d\n", sow);
		return 0;
	}

	// for(int i = 1; i <= n; i++) {
	// 	if(type[i] == 0) cy.push_back(i);
	// }

	search(cyStart);
	printf("%d\n", fsum);

	// int cura = cyStart;
	//
	// while(true) {
	// 	bool foundIt = false;
	// 	for(int i = 0; i < g[cura].size(); i++) {
	// 		int ngb = g[cura][i];
	//
	// 		if(type[ngb] == 0) {
	// 			foundIt = true;
	// 			type[ngb] = 1;
	// 			cy.push_back(ngb);
	// 			cura = ngb;
	// 			break;
	// 		}
	// 	}
	// 	if(!foundIt) break;
	// }
	//
	// for(int i = 0; i < cy.size(); i++) {
	// 	printf("%d ", cy[i]);
	// }
}
