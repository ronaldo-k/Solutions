#include <stdio.h>
#include <deque>
#include <vector>
#include <utility>
#include <algorithm>

#define debug(args...) fprintf(stderr, args);
using namespace std;

const int MAXN = 2e6, INF = 2e9;

int n, m, c, in[MAXN];
int iniMin = 1, fimMin = 1, iniMax = 1, fimMax = 1;

deque < pair < int, int > > minq, maxq;
deque < int > resp;

void insertMin(int ta) {
	fimMin++;

	while( !minq.empty() && minq.back().first > ta ) {
		minq.pop_back();
	}
	minq.push_back( make_pair(ta, fimMin) );
}

void removeMin() {
	if( !minq.empty() && minq.front().second == iniMin ) {
		minq.pop_front();
	}

	iniMin++;
}

int minimum() {
	return minq.front().first;
}

//----------------------------------------------------------------------------//

void insertMax(int ta) {
	fimMax++;

	while( !maxq.empty() && maxq.back().first < ta ) {
		maxq.pop_back();
	}

	maxq.push_back( make_pair(ta, fimMax) );
}

void removeMax() {
	if( !maxq.empty() && maxq.front().second == iniMax) {
		maxq.pop_front();
	}

	iniMax++;
}

int maximum() {
	return maxq.front().first;
}

//----------------------------------------------------------------------------//

int main() {
	int ident = 1, dt = 0;
	bool first;

	scanf("%d %d %d", &n, &m, &c);

	for(int i = 1; i <= n; i++) {
		scanf("%d", &in[i]);
	}

	for(int i = 1; i <= n; i++) {
		insertMax(in[i]); insertMin(in[i]);

		int tmin = minimum();
		int tmax = maximum(); debug("79: ident: %d, dt: %d, max: %d, min: %d\n", ident, dt, tmax, tmin);

		if(tmax - tmin > c) {
			ident = i - 1;

			removeMin(); removeMax();
		}
		if(tmax - tmin <= c && dt >= m) {
			ident = i - 1;
			dt = 0;

			minq.clear(), maxq.clear();
		}
		else {
			dt++;
		}
	}

	for(int i = 0; i < resp.size(); i++) {
		printf("%d\n", resp.front());
		resp.pop_front();
	}
}
