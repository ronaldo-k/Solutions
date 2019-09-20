// DOUBLE SAWTOOTH LOOPS – Isósceles (URI)
// Made on: 26/08/2019

#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXN = 5e4 + 10;
int n, v[MAXN], rtl[MAXN], ltr[MAXN], ans;

int main() {
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	ltr[0] = 1;
	for(int i = 1; i < n; i++) {
		ltr[i] = min(ltr[i-1] + 1, v[i]);
	}

	rtl[n-1] = 1;
	for(int i = n-2; i >= 0; i--) {
		rtl[i] = min(rtl[i+1] + 1, v[i]);
	}

	for(int i = 0; i < n; i++) {
		ans = max(ans, min(rtl[i], ltr[i]));
	}

	printf("%d\n", ans);
}
