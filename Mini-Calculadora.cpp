#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int n, a, b;

int mdc(int x, int y) {
	if(y == 0) return x;
	if(y > x) return mdc(y, x);
	else return mdc(y, x % y);
}

int main() {
	scanf("%d %d %d", &n, &a, &b);
	int div = mdc(a, b);
	a /= div; b /= div;
	int ans = max(a, b);

	if(ans > n) {
		printf("IMPOSSIVEL\n");
	}
	else printf("%d %d\n", a, b);
}
