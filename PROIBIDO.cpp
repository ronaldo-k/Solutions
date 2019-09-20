#include <stdio.h>
#include <set>

using namespace std;

int n, tin;

set < int > s;

int main() {
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		int ta;
		scanf("%d", &ta);

		s.insert(ta);
	}

	while(scanf("%d", &tin) != EOF) {
		if(s.find(tin) != s.end()) printf("sim\n");
		else printf("nao\n");
	}
}
