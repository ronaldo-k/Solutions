#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

const int MAXN = 2e6;

int t, n, d, v[MAXN], m[MAXN], s[MAXN], resp;
int main() {
	scanf("%d", &t);

	for(int c = 0; c < t; c++) {
		scanf("%d %d", &d, &n);

		resp = 0;

		memset(v, 0, sizeof(v));
		memset(m, 0, sizeof(m));

		for(int i = 0; i < n; i++) {
			scanf("%d", &v[i]);

			if(i == 0) s[i] = v[i] % d;
			else s[i] = (s[i-1] + v[i]) % d;
		}

		m[0] = 1;

		for(int i = 0; i < n; i++) {
			resp += m[s[i]];
			m[s[i]]++;
		}

		printf("%d\n", resp);
	}
}
