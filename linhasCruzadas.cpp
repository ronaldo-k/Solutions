#include <stdio.h>

using namespace std;

const int MAXN = 1e5;
int n, bit[MAXN], resp;

void update(int v) {
	while(v <= MAXN) {
		bit[v]++;
		v += v & -v;
	}
}

int query(int v) {
	int resp = 0;
	while(v > 0) {
		resp += bit[v];
		v -= v & -v;
	}
	return resp;
}

int main() {
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) {
		int ta;
		scanf("%d", &ta);

		resp += query(n) - query(ta);

		update(ta);
	}

	printf("%d\n", resp);
}
