// LIS (n^2) – Letras (OBI P1 F2 2015)
// Made on: 10/06/2019

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAXN = 4e5;

int v[MAXN], marc[30], n, ans;
char in[MAXN];

int main() {
	scanf(" %s", in);

	n = strlen(in);

	for(int i = 0; i < n; i++) {
		v[i] = in[i] - 'A' + 1;
	}

	for(int i = 0; i < n; i++) {
		int aux = 0;
		for(int j = 1; j <= v[i]; j++) {
			aux = max(aux, marc[j]);
		}
		marc[v[i]] = aux + 1;
	}

	for(int j = 26; j >= 1; j--) {
		ans = max(ans, marc[j]);
	}

	printf("%d\n", ans);
}
