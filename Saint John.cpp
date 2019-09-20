#include <stdio.h>
#include <vector>
using namespace std;

struct point {
	int x, y;

	struct point operator-(struct point a) {
		struct point aux;

		aux.x = x - a.x;
		aux.y = y - a.y;

		return aux;
	}

	bool operator<(struct point a) const {
		if(x == a.x) return y < a.y;
		return x < a.x;
	}
};

int resp, l, s;
vector < struct point > inPts, inHull, upper, lower, fhull;

//---------------------------//

long long int cross(struct point a, struct point b) {
	return (a.x * a.y) - (a.y * b.x);
}

bool bSearch(struct point cur) {
	bool ok;
	int ini = 0, fim = fhull.size() - 1;
	int m;

	if( cross( fhull[1] - fhull[0], cur - fhull[0]) > 0)
		return false;

	if( cross( fhull[fim] - fhull[ini], cur - fhull[ini] ) < 0)
		return false;

	while(ini < fim) {
		m = (ini + fim) / 2;
		if( cross( fhull[m] - fhull[0], cur - fhull[0] ) >= 0 ) {
			fim = m;
		}
		else ini = m + 1;
	}

	if( fim == 1 && cross( fhull[2] - fhull[1], cur - fhull[1] ) > 0)
		return false;
	else if (fim == 1)
		return true;

	if( cross( fhull[fim] - fhull[fim-1], cur - fhull[fim-1]) > 0)
		return false;
	else
		return true;
}

//---------------------------//

int main() {
	scanf("%d", &l);

	for(int i = 0; i < l; i++) {
		struct point aux;

		scanf("%d %d", &aux.x, &aux.y);

		inHull.push_back(aux);
	}

	scanf("%d", &s);

	for(int i = 0; i < s; i++) {
		struct point aux;

		scanf("%d %d", &aux.x, &aux.y);

		inPts.push_back(aux);
	}

	sort(inHull.begin(), inHull.end());

	int t = -1;
	for(int i = 0; i < l; i++) { // Upper Hull
		while( t >= 1 && cross(upper[t] - upper[t-1], inHull[i] - upper[t-1]) >= 0) {
			t--;
			upper.pop_back();
		}

		t++;
		upper.push_back(inHull[i]);
	}

	t = -1;
	for(int i = 0; i < l; i++) { // Lower Hull
		while( t >= 1 && cross(lower[t] - lower[t-1], inHull[i] - lower[t-1]) <= 0) {
			t--;
			lower.pop_back();
		}

		t++;
		lower.push_back(inHull[i]);
	}

	for(int i = 0; i < upper.size(); i++) {
		fhull.push_back(upper[i]);
	}
	for(int i = lower.size()-2; i > 0; i--) {
		fhull.push_back(lower[i]);
	}

	for(int i = 0; i < s; i++) { // Binary Search
		if( bSearch(inPts[i]) ) resp++;
	}

	printf("%d", resp);
}
