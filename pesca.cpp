#include <stdio.h>

const int MAXN = 200;
int n, resp, v[MAXN][MAXN];

struct rect {
	int x1, x2, y1, y2;
};

int main() {
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		struct rect aux;
		scanf("%d %d %d %d", &aux.x1, &aux.x2, &aux.y1, &aux.y2);

		for(int i = aux.x1; i < aux.x2; i++) {
			for(int j = aux.y1; j < aux.y2; j++) {
				v[i][j] = 1;
			}
		}
	}

	for(int i = 0; i < 100; i++) {
		for(int j = 0; j < 100; j++) {
			if(v[i][j] == 1) resp++;
		}
	}

	printf("%d\n", resp);
}
