// Greedy algorithm – Cable Cars (Codeforces MCO 2017 B)
// Made in: 07/07/2019

/* Guloso:
Aplicar regras do exercício:
Da montanha mais alta, andar para a direita (índices crescentes), armazenar o máximo entre a montanha mais alta (exclusivo) e o índice atual e incrementar a resposta caso a montanha atual for mais alta que o máximo armazenado. Fazer o mesmo p/ a esquerda.
*/

#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXN = 1e6 + 10;
int n, v[MAXN], mh, mhid, ans;

// mh: Morro com maior altura
// mhid: Índice do morro com maior altura

int main() {
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		scanf("%d", &v[i]);

		if(v[i] > mh) {
			mh = v[i];
			mhid = i;
		}
	}

	int curmax = 0;
	for(int i = mhid + 1; i < n; i++) {
		if(v[i] > curmax) ans++;
		curmax = max(curmax, v[i]);
	}

	curmax = 0;
	for(int i = mhid - 1; i >= 0; i--) {
		if(v[i] > curmax) ans++;
		curmax = max(curmax, v[i]);
	}

	printf("%d\n", ans);
}
