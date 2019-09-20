#include <stdio.h>
#include <algorithm>
#include <vector>

#define debug(args...) fprintf(stderr, args);
using namespace std;

int n, q;
vector < int > v;

int main() {
	scanf("%d %d", &n, &q);

	for(int i = 0; i < n; i++) {
		int ta;
		scanf("%d", &ta);
		v.push_back(ta);
	}

	sort(v.begin(), v.end());

	for(int i = 0; i < q; i++) {
		int ta;
		scanf("%d", &ta);

		int resp = lower_bound(v.begin(), v.end(), ta) - v.begin();

		if(v[resp] != ta) printf("-1\n");
		else printf("%d\n", resp);
	}
}
