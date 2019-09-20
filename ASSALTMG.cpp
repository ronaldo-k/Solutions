#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 35;
int ct, m, d, k[MAXN][MAXN], choice[MAXN], ans = MAXN;

void solve(int i) {
	//printf("i = %d ans = %d\n", i, ans);
	if(i > d) return;

	int seq[MAXN];
	memset(seq, 0, sizeof(seq));

	if(i == d) {
		int tans = 0, tnum = 0;

		for(int a = 0; a < d; a++) {
			if(choice[a] == 1) {
				//printf("%d CHOSEN\n", a);
				tans++;
				for(int j = 0; j < 32; j++) {
					seq[j] = max(k[a][j], seq[j]);
					// if(k[a][j] == 1) printf(" -> key %d from %d used\n", j, a);
					// printf("seq[%d] = %d\n", j, seq[j]);
				}
			}
		}

		for(int a = 0; a < 32; a++) {
			if(seq[a] == 1) {
				// printf("key %d detected\n", a);
				tnum++;
			}
		}

		// printf("tnum = %d, m = %d\n", tnum, m);

		if(tnum >= m) ans = min(ans, tans);
		return;
	}

	choice[i] = 1;
	solve(i+1);
	choice[i] = 0;
	solve(i+1);
}

int main() {
	scanf("%d", &ct);

	for(int z = 0; z < ct; z++) {
		memset(k, 0, sizeof(k));
		memset(choice, 0, sizeof(choice));
		ans = MAXN;

		scanf("%d %d", &m, &d);

		for(int i = 0; i < d; i++) {
			int ta;
			scanf("%d", &ta);

			for(int j = 0; j < ta; j++) {
				int tin;
				scanf("%d", &tin);
				k[i][--tin] = 1;
			}
		}

		// for(int i = 0; i < d; i++) {
		// 	for(int j = 0; j < 32; j++) {
		// 		printf("%d ", k[i][j]);
		// 	}
		// 	printf("\n");
		// }

		solve(0);
		if(ans <= 32) printf("%d\n", ans);
		else printf("Desastre!\n");
	}
}
