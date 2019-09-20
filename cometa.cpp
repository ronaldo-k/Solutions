#include <stdio.h>
#include <algorithm>

const int MAXN = 1000;
int n, last = 1986, v[MAXN], now;

int main() {
	scanf("%d", &n);

	v[0] = last;
	for(int i = 1; i < 990; i++) {
		v[i] = v[i-1] + 76;
	}

	now = std::upper_bound(v, v + 990, n) - v;

	printf("%d\n", v[now]);
}
