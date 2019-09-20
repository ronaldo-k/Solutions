// BFS Convencional + Manipulação de Strings – UIQUI7 (SPOJ)
// Link: https://br.spoj.com/problems/UIQUI7/

#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAXN = 2e3;
int n, dist[MAXN], marc[MAXN], qtd = 0;
vector < int > g[MAXN];
vector < string > in;
map < string, int > ni; // Name to ID

void bfs(int b) {
	queue < int > q;

	marc[b] = 1; dist[b] = 0;
	q.push(b);

	while(!q.empty()) {
		int cur = q.front(); q.pop();

		for(int i = 0; i < g[cur].size(); i++) {
			int ngb = g[cur][i];

			if(marc[ngb] == 0) {
				marc[ngb] = 1;
				dist[ngb] = dist[cur] + 1;

				q.push(ngb);
			}
		}
	}
}

int mapInsert(string ta) {
	if(ni.find(ta) == ni.end()) {
		ni.insert( make_pair(ta, qtd) );
		in.push_back(ta);
		return qtd++;
	}
	else return ni[ta];
}

int main() {
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		string ta, tb; int qta, qtb;
		cin >> ta >> tb;

		qta = mapInsert(ta);
		qtb = mapInsert(tb);

		g[qta].push_back(qtb);
		g[qtb].push_back(qta);
	}

	sort(in.begin(), in.end());

	for(int i = 0; i < n-1; i++) {
		if(i < n-1) g[ ni[in[i]] ].push_back( ni[in[i+1]] );
	}
	g[ ni[in[n-1]] ].push_back( ni[in[0]] );

	string ta, tb;

	cin >> ta >> tb;
	bfs(ni[ta]);

	debug("nita = %d, nitb = %d\n", ni[ta], ni[tb]);
	for(int i = 0; i < n; i++) {
		debug("d[%d] --> %d\n", i, dist[i]);
	}

	printf("%d\n", dist[ni[tb]]);
}
