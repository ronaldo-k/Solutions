// Câmara de Compensação (OBI/NEPS)
// Made on: 20/05/2019

#include <stdio.h>
#include <vector>

using namespace std;

const int MAXN = 2e3;
int m, n, prof[MAXN], bans, gans;
/*
prof: Profit (Received - Given)
bans: "Bad" answer (Non-optimized answer)
gans: "Good" answer (Optimized answer)
*/

int main() {
	scanf("%d %d", &m, &n);

	for(int i = 0; i < m; i++) {
		int ta, tcost, tb;
		scanf("%d %d %d", &ta, &tcost, &tb);
		prof[ta] -= tcost; prof[tb] += tcost;
		bans += tcost;
	}

	for(int i = 1; i <= n; i++) {
		if(prof[i] >= 0) gans += prof[i];
	}

	char opt = 'S';
	if(bans == gans) opt = 'N';

	printf("%c\n", opt);
	printf("%d\n", gans);
}
