// Greedy algorithm – Planting Trees (Kattis plantingtrees)
// Made in: 07/07/2019

/* Guloso:
É sempre ideal plantar as árvores que levam mais tempo para crescer antes.
=> Ordenar as árvores e plantar as árvores em ordem de tempo de crescimento decrescente é sempre ideal.
*/

#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXN = 2e5;
int n, v[MAXN], ans, t;

int main() {
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	sort(v, v + n);

	for(int i = n - 1; i >= 0; i--) {
		t++;
		ans = max(ans, v[i] + t);
	}

	printf("%d\n", ans + 1);
}
