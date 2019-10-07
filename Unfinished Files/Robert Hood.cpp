#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct point {
	int x, y;

	point(int tx = 0, int ty = 0) {
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

vector < struct point > v, q, e;

int main() {
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		struct point t;
		scanf("%d %d", &t.x, &t.y);
		v.push_back(t);
	}

	sort(v.begin(), v.end());

	for(int i = 0; i < n; i++) {
		q.push_back(v[i]);

		if(v[i].x == v[i-1].x) {
			continue;
		}

		e.push_back(q[0]); e.push_back(q[q.size()-1]);
		q.empty();
	}

	for(int i = 1; i < e.size(); i++) {
		for(int j = i+1; j < e.size(); j++) {
			ans = max(ans, (e[j]-e[i]).dot(e[j]-e[i]));
		}
	}

	printf("%f\n", sqrt(ans));
}
