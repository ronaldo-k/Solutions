#include <stdio.h>

int n, dx[] = {1, 2, 2, 1, -1, -2, -2, -1}, dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
int resp, forb[8] = {1, 3, 2, 3, 2, 5, 5, 4}, at[2] = {4, 3};

bool check() {
	if(at[0] > 7 || at[1] > 7) return false;

	for(int i = 0; i < 8; i += 2) {
		if(at[0] == forb[i] && at[1] == forb[i+1]) {
			return false;
		}
	}

	return true;
}

int main() {
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		int ta;

		scanf("%d", &ta);
		ta--;

		at[0] += dx[ta];
		at[1] += dy[ta];

		resp++;
		if(check() == false) break;
	}

	printf("%d\n", resp);
}
