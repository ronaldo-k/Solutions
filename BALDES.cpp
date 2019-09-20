// NUMERO DE INVERSOES COM BIT

#include <stdio.h>
#include <string.h>

#define debug(args...) fprintf(stderr, args)

using namespace std;

const int MAXN = 1e5 + 10;

int n;
int v[MAXN], BIT[MAXN];

void update(int a) {
	while(a <= n) {
		BIT[a]++;
		a += a & -a;
	}
}

int query(int a) {
	int resp = 0;
	while(a > 0) {
		resp += BIT[a];
		a -= a & -a;
	}
	return resp;
}

int main() {
	while(true) {
		memset(v, 0, sizeof(v));
		memset(BIT, 0, sizeof(BIT));

		scanf("%d", &n);

		if(n == 0) break;

		long long int r = 0;
		for(int i = 1; i <= n; i++) {
			int ta;
			scanf("%d", &ta);

			r += query(n) - query(ta);

			update(ta);
		}

		if(r % 2 == 0) {
			printf("Carlos\n");
		}
		else {
			printf("Marcelo\n");
		}
		//debug("r = %lld\n",r);
	}
}
