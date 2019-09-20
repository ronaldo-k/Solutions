#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define debug(args...) fprintf(stderr, args);

using namespace std;

struct camisa{
	string cor, tamanho, nome;

	bool operator<(struct camisa b) const {
		if(!(cor == b.cor)) return cor < b.cor;
		if(!(tamanho == b.tamanho)) return tamanho > b.tamanho;
		return nome < b.nome;
	}
};

vector < struct camisa > v;
char in[1000000];

int main() {
	bool first = true;
	while(true) {
		int n;
		scanf("%d", &n);
		if(n == 0) return 0;
		v.clear();

		if(!first) printf("\n");
		else first = false;

		for(int i = 0; i < n; i++) {
			struct camisa aux;

			scanf(" "); gets(in);
			aux.nome = (string)in;

			scanf(" %s", in);
			aux.cor = (string)in;

			scanf(" %s", in);
			aux.tamanho = (string)in;

			v.push_back(aux);
		}

		sort(v.begin(), v.end());

		for(int i = 0; i < n; i++) {
			cout << v[i].cor << " " << v[i].tamanho << " " << v[i].nome << "\n";
		}
	}
}
