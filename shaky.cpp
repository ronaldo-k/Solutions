#include <stdio.h>
#include <algorithm>
#include <vector>

#define debug(args...) fprintf(stderr, args)

using namespace std;

int n, k; // Quantidade de caixas e de alunos
vector < int > v; // Quantidade de doces na caixa i

int test(int r) {
	long long int tresp = 0;

	/*
`	Conta se e possivel dar r doces para k alunos.`
	*/

	for(int i = 0; i < n; i++) {
		//if(v[i] / r == 0) return false;
		//fprintf(stderr, "v[%d] = %d | r = %d | v[i] / r = %d\n", i,v[i],r,v[i]/r);
		debug("v[%d] = %d | r = %d | v[i] / r = %d\n", i,v[i],r,v[i]/r);
		tresp += v[i] / r;
	}

	if(tresp >= k) return true;
	return false;
}

int main() {
	int casos; // Quantidade de casos de teste

	scanf("%d", &casos);

	for(int teste = 0; teste < casos; teste++) {
		v.clear();

		scanf("%d %d", &n, &k);

		for(int i = 0; i < n; i++) {
			int ta;
			scanf("%d", &ta);
			v.push_back(ta);
		}

		// Busca binaria na resposta
		int ini = 0, fim = 1e9;

		while(ini < fim) {
			//fprintf(stderr, "fim = %d | ini = %d\n", fim, ini);
			int m = (ini + fim) / 2;

			if(ini == fim - 1) m = fim;

			if(test(m)) ini = m;
			else fim = m - 1;
		}

		printf("%d\n", ini);
	}
}
