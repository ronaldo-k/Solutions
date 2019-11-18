// GEOMETRY – Target Practice (Kattis)

#include <stdio.h>
#include <string.h>

using namespace std;

const int MAXN = 1e5 + 10, INF = 2e9;

struct point {
	int x, y;

	point(int tx = -INF, int ty = -INF) {
		x = tx, y = ty;
	}
	struct point operator-(struct point a) {
		struct point aux;
		aux.x = x - a.x;
		aux.y = y - a.y;
		return aux;
	}
} v[MAXN];

bool ans = false, mrk[MAXN];
int n;

long long int cross(struct point a, struct point b) {
	return (long long int)(a.x * b.y) - (a.y * b.x);
}

bool test(struct point sa, struct point sb) {
	struct point ra, rb;
	memset(mrk, 0, sizeof(mrk));

	for(int i = 0; i < n; i++) {
		if(cross(sa-sb, v[i]-sb) == 0) mrk[i] = true;
	}

	// for(int i = 0; i < n; i++) {
	// 	printf("%d ", mrk[i]);
	// }
	// printf("\n");

	for(int i = 0; i < n; i++) {
		if(!mrk[i] && ra.x == -INF && ra.y == -INF) ra = v[i];
		else if(!mrk[i] && rb.x == -INF && rb.y == -INF) rb = v[i];
		else if(!mrk[i]) break;
	}

	for(int i = 0; i < n; i++) {
		//printf("ra = (%d, %d), rb = (%d, %d), v[i] = (%d, %d), cross = %lld\n", ra.x, ra.y, rb.x, rb.y, v[i].x, v[i].y, cross(ra-rb, v[i]-rb));
		if(!mrk[i] && cross(ra-rb, v[i]-rb) != 0) return false;
	}

	return true;
}

int main() {
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		scanf("%d %d", &v[i].x, &v[i].y);
	}

	ans = (test(v[0], v[1]) || test(v[1], v[2]) || test(v[0], v[2]));

	if(ans) printf("success\n");
	else printf("failure\n");
}
