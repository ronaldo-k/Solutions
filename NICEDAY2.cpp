#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
struct part {
	int x, y, z;

	bool operator<(struct part a) const {
		return x < a.x;
	}

	/*
	Cada participante é representado por uma
	struct part, contendo os valores de x, y e z.
	O operador "<" declarado acima é utilizado na
	ordenação, para que a função sort() consiga
	ordenar os valores de maneira correta. É des-
	necessário utilizar y ou z como desempate.
	*/
};

const int INF = 2e9, MAXN = 2e5;
int t, n, resp, seg[4 * MAXN];
// Numero de casos de teste, participantes, resposta
// e vetor da Segment Tree
struct part in[MAXN]; // Armazena a entrada

void update(int pos, int ini, int fim, int id, int val) {
	// pos: Indice do nó atual da Segment Tree
	// ini: Inicio do intervalo que o nó atual representa
	// fim: Fim do intervalo que o nó atual representa
	// id: Indice onde se deseja inserir o valor val
	// val: Valor que se deseja inserir

	if(id < ini || id > fim) return;
	if(ini == fim) {
		seg[pos] = val;
		return;
	}

	int m = (ini + fim) / 2, e = 2 * pos, d = e + 1;
	update(e, ini, m, id, val); update(d, m+1, fim, id, val);
	seg[pos] = min(seg[e], seg[d]);
}

int query(int pos, int ini, int fim, int p, int q) {
	if(q < ini || p > fim) return INF;
	if(p <= ini && fim <= q) return seg[pos];

	int m = (ini + fim) / 2, e = 2 * pos, d = e + 1;
	return min(query(e, ini, m, p, q), query(d, m+1, fim, p, q));
}

int main() {
	scanf("%d", &t);
	for(int c = 0; c < t; c++) {
		// O problema possui vários casos de teste

		resp = 0;
		for(int i = 0; i <= 4 * MAXN; i++) seg[i] = INF;

		struct part aux;
		aux.x = 0; aux.y = INF; aux.z = INF; in[0] = aux;

		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d %d %d", &aux.x, &aux.y, &aux.z);
			in[i] = aux;
		}

		sort(in, in + n);

		for(int i = 1; i <= n; i++) {
			if(query(1, 1, n, 1, in[i].y) > in[i].z) {
				resp++;
				update(1, 1, n, in[i].y, in[i].z);
			}
		}
		printf("%d\n", resp);
	}
}
