#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;

#define debug(args...) //fprintf(stderr, args)

const int MAXN = 210, INF = 2e9;
int n, m, in[MAXN][MAXN], sl, sc;

vector < int > cols;
vector < pair < int, int > > lans, cans;

void sortLine(int y) {
	for(int i = 1; i <= m; i++) {
		if(i != in[y][i]) {

			for(int j = 1; j <= m; j++) {
				if(in[y][j] == i && j != i) {
					lans.push_back( make_pair(i, j) );
					int aux = in[y][i]; in[y][i] = in[y][j]; in[y][j] = aux;
				}
			}

		}
	}
}

void sortFirstColumn() {
	for(int i = 1; i <= n; i++) {
		if(i != cols[i]) {

			for(int j = 1; j <= n; j++) {
				if(cols[j] == i && j != i) {
					// debug("BEF: cols[%d] = %d, cols[%d] = %d\n", i, cols[i], j, cols[j]);

					cans.push_back( make_pair(i, j) );
					int aux = cols[i];
					cols[i] = cols[j]; cols[j] = aux;

					// debug("AFT: cols[%d] = %d -> %d\n", j, cols[j], j);
					// debug("   : cols[%d] = %d -> %d\n", i, cols[i], i);
					//
					// for(int z = 1; z < cols.size(); z++ ) {
					// 	debug("%d ", cols[z]);
					// }
					// debug("\n");
				}
			}

		}
	}
}

int main() {
	scanf("%d %d", &n, &m);

	cols.push_back(0);

	for(int i = 1; i <= n; i++) {
		int tmax = -1;
		for(int j = 1; j <= m; j++) {
			scanf("%d", &in[i][j]);
			tmax = max(tmax, in[i][j]);

			if(in[i][j] == 1) {
				sl = i; sc = j;
			}
		}

		debug("tmin: %d, corr: %d\n", tmax, tmax/m);
		cols.push_back( tmax/m );
	}

	sortLine(sl);

	// debug("BEF: cols: %lu\n", cols.size());
	// for(int i = 1; i < cols.size(); i++) {
	// 	debug("%d ", cols[i]);
	// }
	// debug("\n");

	sortFirstColumn();

	printf("%d\n", lans.size() + cans.size());

	for(int i = 0; i < lans.size(); i++) {
		printf("C %d %d\n", lans[i].first, lans[i].second);
	}
	for(int i = 0; i < cans.size(); i++) {
		printf("L %d %d\n", cans[i].first, cans[i].second);
	}
}
