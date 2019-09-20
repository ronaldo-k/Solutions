#include <stdio.h>

const int MAXN = 2e5;
int n, v[MAXN], r[MAXN], resp = 0;

int main() {
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	int rat;
	for(int i = 1; i < n; i++) {
		if(i == 1 || rat == 0) {
			r[i] = v[i] - v[i-1];
			rat = r[i];
		}
		else if(v[i] - v[i-1] != rat && rat != 0) {
			r[i-1] = rat;
			rat = 0;
			resp++;
			continue;
		}
	}
	r[0] = r[1];

	// for(int i = 0; i < n; i++) {
	// 	printf("%d ", r[i]);
	// }
	// printf("\n");

	printf("%d\n", resp + 1);
}
