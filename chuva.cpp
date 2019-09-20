#include <stdio.h>
#include <algorithm>

using namespace std;

#define debug(args...) //fprintf(stderr, args)

const int MAXN = 2e5;
int n, v[MAXN], s = 1e9, ids, d, resp;

int main() {
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		if(v[i] < s){
			ids = i;
			s = v[i];
		}
	}
	int tm = 0, mh = 0;
	for(int i = ids; i < n; i++) {
		if(v[i] >= d) d = max(d, v[i]);
		else break;
	}
	for(int i = ids; i >= 0; i--) {
		if(v[i] >= tm) tm = max(tm, v[i]);
		else break;
	}
	debug("s: %d, d: %d, tm: %d\n", s, d, tm);
	d = min(d, tm);

	for(int i = 0; i < n; i++) {
		mh = max(v[i], mh);
		debug("d: %d, mh: %d\n", d, mh);
		if(v[i] < d && mh >= d) resp++;
	}

	printf("%d\n", resp);
}
