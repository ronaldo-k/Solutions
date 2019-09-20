#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define debug(args...) //fprintf(stderr, args)

const int INF = 2e9, MAXN = 3e5;

int n, resp = 0;
vector < struct plant > in;
vector < int > mini, e, d;

struct plant {
	int x, y, z, w;

	bool operator<(struct plant ta) const {
		return x < ta.x;
	}
};

//--------------------------------------//

int create() {
	mini.push_back(INF);
	e.push_back(-1);
	d.push_back(-1);
	return mini.size() - 1;
}

void updateSeg(int pos, int ini, int fim, int id, int val) {
	if(id < ini || id > fim) return;
	if(ini == fim) {
		mini[pos] = val;
		return;
	}

	int m = (ini + fim) / 2;
	if(id <= m) {
		if(e[pos] == -1) {
			int aux = create();
			e[pos] = aux;
		}
		updateSeg(e[pos], ini, m, id, val);
	}
	else {
		if(d[pos] == -1) {
			int aux = create();
			d[pos] = aux;
		}
		updateSeg(d[pos], m+1, fim, id, val);
	}

	if(d[pos] == -1) {
		mini[pos] = mini[e[pos]];
	}
	else if(e[pos] == -1) {
		mini[pos] = mini[d[pos]];
	}
	else mini[pos] = min(mini[e[pos]], mini[d[pos]]);
}

int querySeg(int pos, int ini, int fim, int p, int q) {
	if(pos == -1) return INF;
	if(p > fim || q < ini) return INF;
	if(p <= ini && fim <= q) {
		return mini[pos];
	}

	int m = (ini + fim) / 2;

	return min( querySeg(e[pos], ini, m, p, q), querySeg(d[pos], m+1, fim, p, q));
}

//--------------------------------------//

void updateBIT(int y, int z, int w) {
	while(y <= n) {
		updateSeg(y, 1, n, z, w);
		y += y & -y;
	}
}

int queryBIT(int y, int z) {
	int resp = MAXN;
	while(y > 0) {
		int qres = querySeg(y, 1, n, 1, z);
		debug("89: querySeg(y = %d, z = %d) =  %d\n", y, z, qres);

		resp = min(resp, qres);
		y -= y & -y;
	}

	return resp;
}

//--------------------------------------//

int main() {
	scanf("%d", &n);

	struct plant aux;
	aux.x = 0; aux.y = 0; aux.z = 0; aux.w = 0;
	in.push_back(aux);

	create();
	for(int i = 1; i <= n; i++) {
		create();
		scanf("%d %d %d %d", &aux.x, &aux.y, &aux.z, &aux.w);

		in.push_back(aux);
	}

	sort(in.begin(), in.end());

	for(int i = 1; i <= n; i++) {
		debug("115: x:%d, y: %d, z: %d, w: %d\n", in[i].x, in[i].y, in[i].z, in[i].w);

		int ty, tz, tw;

		ty = in[i].y; tz = in[i].z; tw = in[i].w;

		debug("121: query(ty=%d, tz=%d) = %d | tw = %d\n", ty, tz, queryBIT(ty, tz), tw);
		if(queryBIT(ty, tz) > tw) {
			resp++;
			updateBIT(ty, tz, tw);
		}
	}

	printf("%d\n", resp);
}
