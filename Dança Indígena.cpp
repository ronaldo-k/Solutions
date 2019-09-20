#include <stdio.h>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>
#include <string.h>

using namespace std;

#define debug(args...) //fprintf(stderr, args)

const int MAXN = 1e6 + 10, MAXE = 1010;

bool validAns = false;
int n, e, ans;
set < int > test;
vector < pair < int, int > > dist;
vector < int > compI;
int mk[MAXN];

// dist: Armazena a entrada.
// test: Armazena quais distancias devem ser testadas.
// mark: Armazena as posições iniciais dos índios.
// mk: Armazena as posições finais dos índios após uma certa quantidade de batidas de tambor.

int findDist(int i, int j) {
	int di = dist[i].first, dj = dist[j].first;
	int sj = dist[j].second;

	if( (dj < di && sj == 1) || (dj > di && sj == -1) ) {
		return abs(dj - di);
	}
	else if ( dj > di && sj == 1 ){
		return (n - dj) + di;
	}
	else {
		return (n - di) + dj;
	}
}

int findNewPos(int i, int inc) {
	int di = dist[i].first, s = dist[i].second;
	debug("findNewPos: i = %d, di = %d, s = %d, inc = %d\n", i, di, s, inc);

	if(s == 1) {
		if(di + inc > n) {
			return (di + inc) - n;
		}
		else {
			return di + inc;
		}
	}
	else {
		if(di - inc <= 0) {
			return n + (di - inc);
		}
		else {
			return di - inc;
		}
	}
}

int main() {
	scanf("%d %d", &n, &e);

	for(int i = 0; i < e; i++) {
		int ta, ts;
		scanf("%d %d", &ta, &ts);
		dist.push_back( make_pair(ta, ts) );
		//mark[ta] = 1;
		compI.push_back(ta);
	}

	sort(dist.begin(), dist.end());

	// if(dist[0].second == 1) {
	// 	for(int i = dist[0].first + 1; i < n; i++) {
	// 		if(mark[i] == 1) test.push_back(i - dist[0].first);
	// 	}
	// }
	// else {
	// 	for(int i = 0; i < n - dist[0].first; i++) {
	// 		if(mark[n - i] == 1) test.push_back(dist[0].first + i + 1);
	// 		debug("n-i = %d, dist = %d\n", n-i, dist[0].first);
	// 	}
	// }
	//
	// for(int i = 0; i < n; i++) {
	// 	debug("%d ", mark[i]);
	// }
	// debug("\n");
	// for(int i = 0; i < test.size(); i++) {
	// 	debug("%d ", test[i]);
	// }
	// debug("\n");

	for(int i = 0; i < e; i++) {
		for(int j = 0; j < e; j++) {
			if(i != j) {
				int newDist = findDist(i, j);
				test.insert(newDist);
			}
		}
	}

	set < int > :: iterator it;

	// printf("TEST:\n");
	// for(it = test.begin(); it != test.end(); it++) {
	// 	printf("%d\n", *it);
	// }

	for(it = test.begin(); it != test.end(); it++) {
		memset(mk, 0, sizeof(mk));

		for(int i = 0; i < e; i++) {
			int newPos = findNewPos(i, *it);
			mk[ newPos ] = 1;

			// debug("newPos for person i = %d --> %d\n", i, newPos);
		}
		// debug("\n\n");

		int validNum = 0;

		for(int i = 0; i < e; i++) {
			if(mk[ compI[i] ] == 1) validNum++;
			// debug("compI[i = %d] = %d --> mk = %d\n", i, compI[i], mk[ compI[i] ]);
		}
		if(validNum == e) {
			ans = *it;
			validAns = true;
			break;
		}
	}

	if(validAns) printf("%d\n", ans);
	else printf("%d\n", n);

	// else {
	// 	for(int i = dist[i].)
	// }
}
