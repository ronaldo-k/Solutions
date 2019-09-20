#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>

using namespace std;

#define debug(args...) //fprintf(stderr, args)

struct point {
	bool inv;
	double x, y;

	point(int inX = 0, int inY = 0, bool inInv = false) {
		x = inX; y = inY; inv = inInv;
	}
	int quadrante() const {
		if(!inv) {
			if(x >= 0) return 1;
			if(x <  0) return 2;
		}
		else {
			if(x <= 0) return 3;
			if(x >  0) return 4;
		}
	}
	struct point operator-(struct point a) {
		struct point aux;
		aux.x = x - a.x;
		aux.y = y - a.y;
		return aux;
	}
	double cross(struct point a) const {
		return (x * a.y) - (y * a.x);
	}
	double dot(struct point a) const {
		return (x * a.x) + (y * a.y);
	}

	bool operator<(struct point a) const {
		if(quadrante() != a.quadrante()) return quadrante() < a.quadrante();
		if(cross(a) == 0) return dot(*this) < a.dot(a);

		return cross(a) > 0;
	}
};

const int MAXN = 30010;

int c, p, sc[MAXN], sp[MAXN];
vector < pair < struct point, int > > v;

int main() {
	while(true) {
		bool isValid = false;

		v.clear();
		memset(sc, 0, sizeof(sc));
		memset(sp, 0, sizeof(sp));

		scanf("%d %d", &c, &p);

		if(c == -1 && p == -1) return 0;

		for(int i = 0; i < c; i++) {
			struct point aux;
			scanf("%lf %lf", &aux.x, &aux.y);

			if(aux.y < 0) {
				aux.x = -aux.x, aux.y = -aux.y;
				aux.inv = true;
			}

			v.push_back( make_pair(aux, 0) );
		}

		for(int i = 0; i < p; i++) {
			struct point aux;
			scanf("%lf %lf", &aux.x, &aux.y);

			if(aux.y < 0) {
				aux.x = -aux.x, aux.y = -aux.y;
				aux.inv = true;
			}

			v.push_back( make_pair(aux, 1) );
		}

		sort(v.begin(), v.end());

		for(int i = 0; i < v.size(); i++) {
			debug("%d -> %f %f (%d)\n", i, (v[i].first).x, (v[i].first).y, v[i].second);

			sc[i] = sc[i-1]; sp[i] = sp[i-1];

			if(v[i].second == 0) sc[i]++;
			if(v[i].second == 1) sp[i]++;

			debug("sc[%d] = %d, sp[%d] = %d\n", i, sc[i], i, sp[i]);
		}

		for(int i = 0; i < v.size(); i++) {
			debug("%d -> %d %d, %d %d\n", i, sc[i], c-sc[i], sp[i], p-sp[i]);
			if(sc[i] == c - sc[i] && sp[i] == p - sp[i]) {
				printf("YES\n");
				isValid = true;
				break;
			}
		}

		if(!isValid) printf("NO\n");
	}
}
