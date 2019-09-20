#include <stdio.h>

const int MAXN = 2e5;

int n, k;
int v[MAXN], marc[MAXN], pos[MAXN];

int main() {
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		int ta;
		scanf("%d", &ta);
		v[i] = ta;
		pos[ta] = i;
	}

	scanf("%d", &k);

	for(int i = 0; i < k; i++) {
		int ta;
		scanf("%d", &ta);
		marc[pos[ta]] = 1;
	}

	for(int i = 0; i < n; i++) {
		if(marc[i] == 1) continue;
		else if(i < n - 1) printf("%d ", v[i]);
		else printf("%d", v[i]);
	}
}
