// LINE SWEEP - Robert Hood (Kattis NCPC 2013)

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

int n, ans;

vector < struct point > v, e;

int main() {
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		struct point t;
		scanf("%d %d", &t.x, &t.y);
		v.push_back(t);
	}

	sort(v.begin(), v.end());

	e.push_back(v[0]);

	int last = 0;
	for(int i = 1; i < n; i++) {
		if(v[i].x != v[i-1].x) {
			e.push_back(v[i]); e.push_back(v[i-1]);
			last = i;
		}
	}
	
	e.push_back(v[n-1]);
	
	for(int i = 0; i < e.size(); i++) {
		for(int j = i+1; j < e.size(); j++) {
			ans = max(ans, (e[j]-e[i]).dot(e[j]-e[i]));
		}
	}

	printf("%.10f\n", sqrt(ans));
}
