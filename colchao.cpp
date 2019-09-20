#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

#define debug(args...) //fprintf(stderr, args)

int h, l;
bool ans = false;
vector < int > v;

int main() {
	for(int i = 0; i < 3; i++) {
		int ta;
		scanf("%d", &ta);
		v.push_back(ta);
	}
	sort(v.begin(), v.end());
	scanf("%d %d", &h, &l);

	if(l < h) {
		int aux = l;
		l = h;
		h = aux;
	}

	debug("v: %d %d %d | p: %d %d\n", v[0], v[1], v[2], h, l);

	if(v[0] <= h && v[1] <= l) ans = true;

	if(ans) printf("S\n");
	else printf("N\n");
}
