#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define debug(args...) //fprintf(stderr, args)
#define show(args...) fprintf(stderr, args)

struct rect {
	int x1, y1, x2, y2;
};2

const int MAXN = 2000, INF = 2e9;

int e, xi, yi, xf, yf, dist[MAXN];
vector < int > g[MAXN], w[MAXN];
vector < struct rect > in;

int findDist(struct rect a, struct rect b) {
	// Se os retângulos possuem alguma intersecção
	if((b.x1 <= a.x2 && b.y1 < a.y2) || (b.x1 < a.x2 && b.y1 <= a.y2)) {
		//debug("intersec: %d %d %d %d\n", b.x1, a.x2, b.y1, a.y2);
		return 0;
	}

	if(a.x1 < b.x2 && a.x1 > b.x1) {
		if(b.y1 > a.y2) return (b.y1 - a.y2);
		if(b.y2 < a.y1) return (a.y1 - b.y2);
	}

	if(a.y1 < b.y2 && a.y1 > b.y1) {
		if(b.x1 > a.x2) return (b.x1 - a.x2);
		if(b.x2 < a.x1) return (a.x1 - b.x2);
	}
}

int pointDist(struct rect a, int x, int y, int id) {
	int xt1 = a.x1, yt1 = a.y2, xt2 = a.x2, yt2 = a.y1;

	if(x > a.x1 && x < a.x2 && y > a.y1 && y < a.y2) {
		return 0;
	}

	if(x > a.x1 && x < a.x2) {
		return min(abs(a.y2 - y), abs(a.y1 - y));
	}
	else if(y > a.y1 && y < a.y2) {
		return min(abs(a.x2 - x), abs(a.x1 - x));
	}

	int tans = min( (abs(a.x1 - x) + abs(a.y1 - y)), (abs(a.x2 - x) + abs(a.y2 - y)) );
	tans = min(tans, min( (abs(xt1 - x) + abs(yt1 - y)), (abs(xt2 - x) + abs(yt2 - y)) ));

	debug("pointDist (%d %d | %d) tans: %d\n", x, y, id, tans);

	return tans;
}

void dijkstra(int v) {
	set < pair < int, int > > q;

	for(int i = 0; i < e + 2; i++) {
		if(i != v) {
			dist[i] = INF;
			q.insert( make_pair(INF, i) );
		}
	}

	dist[v] = 0;
	q.insert( make_pair(0, v) );

	while(!q.empty()) {
		int cur = q.begin()->first; q.erase(q.begin());

		for(int i = 0; i < g[cur].size(); i++) {
			int ngb = g[cur][i], p = w[cur][i];

			if(dist[ngb] > dist[cur] + p) {
				q.erase( make_pair(dist[ngb], ngb) );
				dist[ngb] = dist[cur] + p;
				q.insert( make_pair(dist[ngb], ngb) );
			}
		}
	}
}

int main() {
	scanf("%d %d %d %d %d", &xi, &yi, &xf, &yf, &e);

	struct rect nullrect;
	nullrect.x1 = nullrect.x2 = nullrect.y1 = nullrect.y2 = 0;
	in.push_back(nullrect);

	if(e == 0) {
		printf("%d\n", abs(xf - xi) + abs(yf - yi));
		return 0;
	}

	for(int i = 1; i <= e; i++) {
		struct rect aux;
		scanf("%d %d %d %d", &aux.x1, &aux.y1, &aux.x2, &aux.y2);

		for(int j = 1; j < i; j++) {
			debug("j: %d\n", j);
			if(i != j) {
				g[i].push_back(j);
				g[j].push_back(i);

				int curd = findDist(aux, in[j]);

				debug("1: i: %d | curd: %d\n", i, curd);

				w[i].push_back( curd );
				w[j].push_back( curd );
			}
		}
		in.push_back(aux);
	}

	for(int i = 1; i <= e; i++) {
		g[0].push_back(i);
		g[i].push_back(0);

		int curd = pointDist(in[i], xi, yi, i);
		debug("2: i: %d | curd: %d\n", i, curd);

		w[0].push_back( curd );
		w[i].push_back( curd );
	}

	for(int i = 0; i <= e; i++) {
		g[e+1].push_back(i);
		g[i].push_back(e+1);

		//show("i: %d\n", i);
		//debug("in[%d]: %d %d %d %d\n", i, in[i].x1, in[i].y1, in[i].x2, in[i].y2);
		int curd = pointDist(in[i], xf, yf, i);
		debug("3: i: %d | curd: %d\n", i, curd);

		w[e+1].push_back( curd );
		w[i].push_back( curd );
	}

	dijkstra(0);

	printf("%d\n", dist[e+1]);
}
