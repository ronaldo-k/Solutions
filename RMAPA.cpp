#include <bits/stdc++.h>
using namespace std;

const int maxn = 510;
int prof[maxn], pai[maxn],resp = 0;

struct aresta {
	int a, b, p;
};

vector < struct aresta > v;

int find(int v) {
	if(pai[v] == v) return v;
	else return pai[v] = find(pai[v]); 
}

void une(int a, int b) {
	a = find(a);
	b = find(b);
	if(a==b) return;
	if(prof[a] > prof[b]) {
		pai[b] = a;
		return;
	}
	pai[a] = b;
	if(prof[a] == prof[b]) {
		prof[b]++;
	}
}

bool cmp (struct aresta a, struct aresta b) {
	return a.p < b.p;
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++) {
		pai[i] = i;
		prof[i] = 0;
	}
	for(int i = 0; i < m; i++) {
		int ta, tb, tc;
		scanf("%d%d%d",&ta,&tb,&tc); ta--; tb--;
		aresta aux;
		aux.a = ta; aux.b = tb; aux.p = tc;
		v.push_back(aux);
	}
	sort(v.begin(), v.end(), cmp);
	for(int i = 0; i < m; i++) {
		int ta = v[i].a, tb = v[i].b, tc = v[i].p;
		if(find(ta) != find(tb)) {
			une(ta, tb);
			resp += tc;
		}
	}
	printf("\n%d\n", resp);
}