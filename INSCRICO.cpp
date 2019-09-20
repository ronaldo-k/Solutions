#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

string temp;
map < string, int > m;
vector < string > ordem;

int main() {
	while(true) {
		m.clear();
		ordem.clear();
		temp.clear();

		int n, count = 0;

		scanf("%d", &n);
		if(n == 0) return 0;

		for(int i = 0; i < n; i++) {
			char cTemp[22], cNome[22];

			scanf(" %s", cNome);
			scanf(" %s", cTemp);

			temp = (string)cTemp;

			if(m.find(temp) == m.end()) ordem.push_back(temp);
			m[temp]++;
		}

		for(int i = 0; i < ordem.size(); i++) {
			cout << ordem[i];
			printf(" %d\n", m[ordem[i]]);
		}
	}
}
