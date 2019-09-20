#include <stdio.h>
#include <string.h>

#define debug(args...) //fprintf(stderr, args)

const int MAXN = 2e5;

int n, v[MAXN], casos;
char ign, q[MAXN];

int main() {
	scanf("%d", &casos);

	for(int teste = 0; teste < casos; teste++) {
		memset(v, 0, sizeof(v));

		scanf("%s", q);

		scanf("%d", &n);

		int fim = n, ini = 0;
		bool isInverted = false;
		char ign2;

		if(n > 0) {
			scanf(" %c", &ign);
			for(int i = 0; i < n; i++) {
				scanf("%d %c", &v[i], &ign);
			}
		}
		else scanf(" %c %c", &ign, &ign2);

		for(int i = 0; i < strlen(q); i++) {
			debug("ini = %d, fim = %d\n", ini, fim);

			if(q[i] == 'R') isInverted ^= true;

			if(q[i] == 'D') {
				if(!(isInverted)) {
					ini++;
				}
				else {
					fim--;
				}
			}
		}

		debug(" > > > > > %d %d\n", ini, fim);

		if(ini == fim) {
			printf("[]\n");
			continue;
		}

		if(fim - 1 < ini) {
			printf("error\n");
			continue;
		}

		printf("[");

		if(!(isInverted)) {
			for(int i = ini; i < fim; i++) {
				if(i == fim - 1) printf("%d", v[i]);
				else printf("%d,", v[i]);
			}
		}

		else {
			for(int i = fim - 1; i >= ini; i--) {
				if(i == ini) printf("%d", v[i]);
				else printf("%d,", v[i]);
			}
		}
		printf("]\n");
	}
}
