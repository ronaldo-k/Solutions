#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXN = 2010;

int n, m, q, BIT[MAXN][MAXN], cap[MAXN][MAXN];

void update(int x, int y, int val) {
	int ySalvo = y;

	while(x < MAXN) {
		y = ySalvo;

		while(y < MAXN) {
			BIT[x][y] += min(val, cap[x][y]);

			if(BIT[x][y] == cap[x][y]) val -= cap[x][y];
			y += y & -y;
		}

		x += x & -x;
	}

}

int query(int x, int y) {
	int ySalvo = y, resp = 0;

	while(x > 0) {
		y = ySalvo;

		while(y > 0) {
			resp += BIT[x][y];
			y -= y & -y;
		}

		x -= x & -x;
	}

	return resp;
}

int main() {
	scanf("%d %d %d", &n, &m, &q);

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%d", &cap[i][j]);
		}
	}

	for(int i = 0; i < q; i++) {
		int tipo, x1, y1, x2, y2;

		scanf("%d", &tipo);

		if(tipo == 1) {
			scanf("%d %d %d", &x1, &y1, &x2);

			update(x1, y1, x2);
		}
		else {
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

			int x2y2 = query(x2,y2);
			int x1y2 = query(x1 - 1, y2);
			int x2y1 = query(x2, y2 - 1);
			int x1y1 = query(x1 - 1, y1 - 1);

			printf("%d\n", x2y2 - x1y2 - x2y1 + x1y1);
		}
	}

}
