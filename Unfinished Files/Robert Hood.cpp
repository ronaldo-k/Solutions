#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

#define debug(args...) //fprintf(stderr, args)

const int INF = 2e9;

struct point {
	int x, y;

	point(int tx = -INF, int ty = -INF) {
		x = tx;
		y = ty;
	}
	struct point operator-(struct point a) {
		struct point aux;
		aux.x = x - a.x;
		aux.y = y - a.y;
		return aux;
	}
	int dot(struct point a) {		
		return (x * a.x) + (y * a.y);
	}

	bool operator<(struct point a) const {
		if(x == a.x) return y < a.y;
		return x < a.x;
	}
};

int n;
long long int ans;

vector < struct point > v, e;

int main() {
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		struct point t;
		scanf("%d %d", &t.x, &t.y);
		v.push_back(t);
	}

	sort(v.begin(), v.end());

	for(int i = 0; i < n; i++) {
		debug("[%d] -> (%d, %d)\n", i, v[i].x, v[i].y);
	}

	e.push_back(v[0]);
	debug("inserting %d\n", 0);

	int last = 0;
	for(int i = 1; i < n; i++) {
		if(v[i].x != v[i-1].x) {
			debug("This range = from %d to %d\n", last, i);
			e.push_back(v[last]); e.push_back(v[i-1]);
			last = i+1;
		}
	}
	
	debug("inserting %d\n", n-1);
	e.push_back(v[n-1]);
	
	for(int i = 0; i < e.size(); i++) {
		for(int j = 0; j < e.size(); j++) {
			if(i != j) ans = max(ans, (long long int)(e[j]-e[i]).dot(e[j]-e[i]));
		}
	}

	printf("%2f\n", sqrt(ans));
}
