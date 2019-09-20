// BACKTRACKING – Recibo de Compra (OBI) – P1 F3 2018
// Made on: 27/05/2019

#include <stdio.h>
#include <algorithm>
#define debug(args...) fprintf(stderr, args);

using namespace std;

const int MAXN = 110, MAXK = 25;
int ans, n, k;

void bt(int sum, int last, int id) {
	if(sum + (last * (k-id)) > n) return;
	if(id == k+1) {
		if(sum == n) ans++;
		return;
	}

	for(int i = last + 1; i < n; i++) {
		bt(sum + i, i, id + 1);
	}
}

int main() {
	scanf("%d %d", &n, &k);

	ans = 0;
	if(k > 1) bt(0, 0, 1);
	else ans = 1;

	printf("%d\n", ans);
}
