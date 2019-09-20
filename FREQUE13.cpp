#include <stdio.h>
#include <set>

using namespace std;

int resp;

set < int > s;

int main() {
	int n;
	scanf("%d", &n);
	resp = n;

	for(int i = 0; i < n; i++) {
		int ta;
		scanf("%d", &ta);

		if(s.find(ta) == s.end()) s.insert(ta);
		else resp--;
	}

	printf("%d\n", resp);
}
