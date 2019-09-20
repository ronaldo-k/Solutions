#include <stdio.h>
#include <vector>

#define debug(args...) //fprintf(stderr, args);
using namespace std;

const int MAXN = 510, INF = 2e9;
int n, m, k, c[MAXN], inv[MAXN], id[MAXN], minId, marc[MAXN];

vector < int > g[MAXN];

/*
n: Numero de vertices
m: Numero de arestas
k: Numero de queries

c[]: Guarda o vertice correto (apos as trocas de gerencia) na posicao original
	de i. Por exemplo, trocam-se os lugares dos vertices i e j:

	Antes da troca: c[i] = i, c[j] = j
	Apos a troca: c[i] = j, c[j] = i

	No inicio, ja que todos os vertices estao em suas posicoes originais,
	c[v] = v para todo vertice v.
inv[]: Guarda o identificador do empregado no vertice i. Portanto:
	c[i] = j => inv[j] = i

id[]: Guarda as idades (Indexadas como no grafo inicial, antes das trocas).
minId: Idade minima (Utilizado na dfs. A DFS e void, portanto retornara nada,
mas atualizara o valor de minId para a query atual).

marc[]: Vetor de marcacao para a DFS
*/

void dfs(int ta) {
	marc[ta] = 1;

	for(int i = 0; i < g[ta].size(); i++) {
		int viz = g[ta][i];

		if(marc[viz] == 0) {
			minId = min(id[c[viz]], minId);
			debug("viz = %d, c = %d, id[c] = %d, id[viz] = %d, minId = %d\n", viz, c[viz], id[c[viz]], id[viz], minId);

			dfs(viz);
		}
	}
}

int main() {

	// Entrada
	scanf("%d %d %d", &n, &m, &k);

	for(int i = 1; i <= n; i++) {
		// Construcao de c[] como descrito acima e entrada das idades

		scanf("%d", &id[i]);
		c[i] = i;
		inv[i] = i;
	}

	for(int i = 1; i <= m; i++) {
		int ta, tb;
		// A entrada fornece o grafo direcionado de forma que ta e o gerente de
		// tb. Para calcular a idade minima dos gerentes de certo vertice, deve-
		// mos passar pelo grafo reverso (tb e gerenciado por ta, portanto tb
		// --> ta). O grafo na direcao fornecida pelo exercicio (ta e gerente de
		// tb, portanto ta --> tb) nao sera usado.

		scanf("%d %d", &ta, &tb);
		g[tb].push_back(ta);
	}

	for(int i = 1; i <= k; i++) {
		// Entrada das queries

		char top; int ta, tb;
		scanf(" %c %d", &top, &ta);

		if(top == 'P') {
			// Pergunta da idade minima
			minId = INF;
			ta = c[ta];

			memset(marc, 0, sizeof(marc));

			dfs(ta);

			if(minId < INF) printf("%d\n", minId);
			else printf("*\n");
		}
		if(top == 'T') {
			// Troca de gerencia.

			scanf("%d", &tb);

			debug("(ORIGINAL) ta = %d, tb = %d\n", ta, tb);
			ta = inv[ta];
			tb = inv[tb]; // Indice original --> Indice atual
			debug("(ATUAL) ta = %d, tb = %d\n", ta, tb);

			int aux = inv[c[ta]];
			inv[c[ta]] = inv[c[tb]];
			inv[c[tb]] = aux;

			aux = c[ta];
			c[ta] = c[tb];
			c[tb] = aux;
		}
	}
}
