#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

#define debug(args...) //fprintf(stderr, args)

const int MAXN = 600;
int n, m, resp;
int pai[MAXN], prof[MAXN];

struct aresta{
	int a, b, weight;
};

vector < int > in;
vector < struct aresta > v;

bool comp(struct aresta ta, struct aresta tb) {
	return ta.weight < tb.weight;
}

int find(int ta) {
	if(pai[ta] == ta) return ta;
	return pai[ta] = find(pai[ta]);
}

bool une(int ta, int tb) {
	ta = find(ta);
	tb = find(tb);

	if(pai[ta] == pai[tb]) return true;

	if(prof[ta] > prof[tb]) {
		pai[tb] = ta;
	}
	else pai[ta] = tb;

	if(prof[ta] == prof[tb]) {
		prof[ta]++;
	}
	return false;
}

int main() {
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++) {
		prof[i] = 0;
		pai[i] = i;
	}

	for(int i = 0; i < m; i++) {
		int ta, tb, tw;
		struct aresta aux;
		scanf("%d %d %d", &ta, &tb, &tw);

		aux.a = ta;
		aux.b = tb;
		aux.weight = tw;

		v.push_back(aux);
	}

	sort(v.begin(), v.end(), comp);

	for(int i = 0; i < m; i++) {
		if(!une(v[i].a, v[i].b)) {
			debug("nao estavam unidos antes\n");
			in.push_back(v[i].weight);
		}
	}

	for(int i = 0; i < in.size(); i++) {
		resp += in[i];
	}

	printf("%d\n", resp);
}
