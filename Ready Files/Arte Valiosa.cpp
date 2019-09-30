// GEOMETRY – Arte Valiosa (Maratona de Programação 2019)

#include <stdio.h>

using namespace std;

#define debug(args...) //fprintf(stderr, args)

const int MAXN = 1010;

struct circle {
	long long int x, y, r;

	struct circle operator-(struct circle a) {
		struct circle aux;
		aux.x = x - a.x;
		aux.y = y - a.y;
		return aux;
	}
} v[MAXN], o, w1, w2, w3, w4;

bool isValid = true;
int n, m, k, fat[MAXN], dpt[MAXN];

long long int dot(struct circle a, struct circle b) {
	return a.x * b.x + a.y * b.y;
}

int find(int v) {
	if(fat[v] == v) return v;
	return fat[v] = find(fat[v]);
}

void join(int a, int b) {
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
	scanf("%d %d %d", &n, &m, &k);

	for(int i = 0; i < k; i++) {
		struct circle a;
		scanf("%lld %lld %lld", &a.x, &a.y, &a.r);
		v[i] = a;
	}

	for(int i = 0; i < k+4; i++) {
		fat[i] = i; dpt[i] = 0;
	}

	for(int i = 0; i < k; i++) {
		for(int j = 0; j < k; j++) {
			if(i != j) {
				long long int tans = (v[i].r + v[j].r);

				if(dot(v[j]-v[i], v[j]-v[i]) <= tans * tans) {
					join(i, j);
				}
			}
		}
	}

	for(int i = 0; i < k; i++) {
		w1.x = v[i].x, w1.y = 0;
		w2.x = 0, w2.y = v[i].y;

		if(dot(v[i] - w1, v[i] - w1) <= v[i].r * v[i].r) {
			join(i, k);
		}
		if(dot(v[i] - w2, v[i] - w2) <= v[i].r * v[i].r) {
			join(i, k+1);
		}

		w1.x = v[i].x, w1.y = m;
		w2.x = n, w2.y = v[i].y;

		if(dot(v[i] - w1, v[i] - w1) <= v[i].r * v[i].r) {
			join(i, k+2);
		}
		if(dot(v[i] - w2, v[i] - w2) <= v[i].r * v[i].r) {
			join(i, k+3);
		}
	}

	for(int i = k; i < k+4; i++) {
		for(int j = k; j < k+4; j++) {
			if(i >= j) continue;
			if((i == k && j == k+3) || (i == k+1 && j == k+2)) continue;

			if(i < j && find(i) == find(j)) {
				debug("%d != %d\n", i-k, j-k);
				isValid = false;
				break;
			}
		}
	}

	if(isValid) printf("S\n");
	else printf("N\n");
}
