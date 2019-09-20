// KRUSKAL (MST USING UNION-FIND) — REDOTICA (SPOJ)
// Made on: 20/05/2019

#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 200;
int n, m, tc, fat[MAXN], dpt[MAXN];
struct edge {
	int a, b, w;

	bool operator<(struct edge e) const {
		if(w == e.w && a == e.a) return b < e.b;
		else if(w == e.w) return a < e.a;
		else return w < e.w;
	}
};

vector < struct edge > in, ans;

int find(int v) {
	if(fat[v] == v) return v;
	else return fat[v] = find(fat[v]);
}

void connect(int a, int b) {
	a = find(a); b = find(b);

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
	while(scanf("%d %d", &n, &m) != EOF && n != 0 && m != 0) {
		tc++;

		for(int i = 1; i <= n; i++) {
			fat[i] = i;
			dpt[i] = 0;
		}
		in.clear(); ans.clear();

		for(int i = 0; i < m; i++) {
			struct edge ta;
			scanf("%d %d %d", &ta.a, &ta.b, &ta.w);

			in.push_back(ta);
		}

		sort(in.begin(), in.end());

		for(int i = 0; i < m; i++) {
			if(find(in[i].a) != find(in[i].b)) {
				connect(in[i].a, in[i].b);

				struct edge aux;
				aux.a = in[i].a; aux.b = in[i].b; aux.w = 0;

				ans.push_back(aux);
			}
		}

		sort(ans.begin(), ans.end());

		printf("Teste %d\n", tc);
		for(int i = 0; i < ans.size(); i++) {
			int ta = ans[i].a, tb = ans[i].b;
			if(ta < tb) printf("%d %d\n", ta, tb);
			else printf("%d %d\n", tb, ta);
		}
	}
}
