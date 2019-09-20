#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

#define debug(args...) fprintf(stderr, args);

const int MAXN = 1e5, MAXV = 1e6, INF = 2e9;
int nin, vA[MAXN], vB[MAXN], v[MAXN], qtderr;

int lastNum;
int xorRNG() {
	srand(time(NULL));
	int a = rand() + (lastNum << 3);

	a ^= a << 4;
	a ^= lastNum >> 8;

	lastNum = (a * a) - lastNum * 2;
	return abs(a);
}

int mainA(int n) {
	int ansA = INF;

	sort(vA, vA + n + 1);

	for(int i = 0; i <= n; i++) {
		ansA = min(ansA, vA[i] + n - i);
	}

	//printf("%d\n", ansA);
	return ansA;
}

int mainB(int n) {
	int ansB = 0, c = 0;

	sort(vB + 1, vB + n + 1);

	for(int i = n; i >= 1; i--) {
		if(vB[i] - c > i) {
			ansB++;
		}
		else {
			c += vB[i]; ansB += vB[i];
			break;
		}
	}

	//printf("%d\n", ansB);
	return ansB;
}


int main() {
	for(int j = 0; j < 100; j++) {
		for(int i = 0; i < 100; i++) {
			memset(vA, 0, sizeof(vA));
			memset(vB, 0, sizeof(vB));
			int nin = xorRNG() % (MAXN + 1);

			for(int i = 1; i <= nin; i++) {
				int temp = xorRNG() % (MAXV + 1);
				vA[i] = temp;
				vB[i] = temp;
			}

			int ra = mainA(nin), rb = mainB(nin);

			if(ra != rb) {
				printf("Caso %d - ERRO:\nEntrada:\n%d\n", i, nin);
				for(int i = 1; i <= nin; i++) {
					printf("%d ", vA[i]);
				}
				printf("\n");

				printf("\nSaida do Codigo A:\n%d\n", ra);
				printf("\nSaida do Codigo B:\n%d\n\n", rb);
				qtderr++;
			}
		}

		printf("100 casos testados, %d erros\n", qtderr);
		usleep(2000000);
	}
}
