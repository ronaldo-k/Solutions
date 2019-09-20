// UNION-FIND — FUSOES1 (SPOJ)
// Made on: 20/05/2019

#include <stdio.h>

const int MAXN = 2e5;
int n, k, fat[MAXN], dpt[MAXN];

int find(int v) {
	if(fat[v] == v) return v;
	else return fat[v] = find(fat[v]);
}

void connect(int a, int b) {
	a = find(a); b = find(b);

	if(a == b) return;

	else if(dpt[a] > dpt[b]) {
		fat[b] = a;
		return;
	}

	fat[a] = b;
	if(dpt[a] == dpt[b]) {
		dpt[b]++;
	}
}

int main() {
	scanf("%d %d", &n, &k);

	for(int i = 1; i <= n; i++) {
		fat[i] = i;
		dpt[i] = 0;
	}

	for(int i = 0; i < k; i++) {
		char top; int ta, tb;
		scanf(" %c %d %d", &top, &ta, &tb);

		if(top == 'C') {
			if(find(ta) == find(tb)) printf("S\n");
			else printf("N\n");
		}
		else {
			connect(ta, tb);
		}
	}
}
