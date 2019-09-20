#include <stdio.h>

const int MAXN = 1010;
int n, m, v[MAXN], delta[MAXN], resp;

int main() {
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++) {
		scanf("%d", &v[i]);

		delta[i] = m - v[i];
	}

	for(int i = 0; i < n; i++) {
		resp += (delta[i] < 0) ? -delta[i] : delta[i];

		delta[i+1] -= delta[i]; delta[i] = 0;
	}

	printf("%d\n", resp);
}
