#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

vector < int > ordem;
map < int, int > freq;
set < int > in;

int main() {
	int ta;
	while (scanf("%d", &ta) != EOF) {
		if(ta == 0) break; // REMOVER
		if(in.find(ta) == in.end()) {
			ordem.push_back(ta);
			in.insert(ta);
		}
		freq[ta]++;
	}

	for(int i = 0; i < ordem.size(); i++) {
		printf("%d %d\n", ordem[i], freq[ordem[i]]);
	}
}
