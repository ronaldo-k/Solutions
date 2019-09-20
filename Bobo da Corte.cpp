// Bobo da Corte (Maratona de Programação 2019 - B)

#include <stdio.h>

int n, m;
int main() {
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		int ta;
		scanf("%d", &ta);
		if(i == 0) m = ta;
		else if(ta > m) {
			printf("N\n");
			return 0;
		}
	}

	printf("S\n");
}
