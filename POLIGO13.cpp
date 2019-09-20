#include <stdio.h>
#include <algorithm>

#define debug(args...) //fprintf(stderr, args);
using namespace std;

const int MAXN = 2e5;

int soma, v[MAXN], resp;

int main() {
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		soma += v[i];
	}

	sort(v, v + n);

	resp = n;
	soma -= v[n-1];

	for(int i = 1; i <= n; i++) {
		debug("soma = %d, resp = %d, i = %d\n", soma, resp, i);
		if(v[n-i] < soma) break;
		else {
			soma -= v[n-i-1];
			resp--;
		}
	}

	printf("%d\n", resp);
}
