#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>

#define debug(args...) //fprintf(stderr, args);

using namespace std;

int c, t; long long int resp; // Quantidade de círculos e tiros; Pontuacao total
vector < long long int > v; // Guarda o raio dos círculos em ordem crescente

int main() {
	scanf("%d %d", &c, &t);

	for(int i = 0; i < c; i++) {
		long long int ta;
		scanf("%lld", &ta);
		v.push_back(ta*ta);
	}

	sort(v.begin(), v.end()); // 1 4 25

	for(int i = 0; i < t; i++) {
		long long int ta, tb;
		scanf("%lld %lld", &ta, &tb);

		long long int dist = (ta * ta) + (tb * tb);

		int upper = lower_bound(v.begin(), v.end(), dist) - v.begin();

		debug("upper = %d, c- = %d\n", upper, c - upper);

		resp += c - upper;

		//debug("dist = %lld | resp = %lld\n", dist, resp);
	}

	printf("%lld\n", resp);
}
