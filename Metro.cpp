#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 3e4;
vector < int > v[MAXN];
queue < int > proc;

int n, m, pai[MAXN], marc[MAXN], grau[MAXN], resp;

int main() {
	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; i++) {
		int ta, tb;
		scanf("%d %d", &ta, &tb);

		v[ta].push_back(tb);
		v[tb].push_back(ta);

		grau[ta]++; grau[tb]++;
	}

	for(int i = 1; i <= n; i++) {
		if(grau[i] == 1) proc.push(i);

		if(grau[i] >= 5) {
			marc[i] = 1;

			for(int g = 0; g < v[i].size(); g++) {
				int viz = v[i][g];
				if(grau[viz] == 2) proc.push(1);
			}
		}
	}

	while( !(proc.empty()) ) {
		int now = proc.front();
		proc.pop();
		marc[now] = 1;

		int viz = v[now][0];

		if(marc[viz] == 0) {
			grau[viz]--;
			proc.push(viz);
		}
	}

	for(int i = 1; i <= n; i++) {
		if(marc[i] == 0) resp++;
	}

	printf("%d\n", resp);
}
