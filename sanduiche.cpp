#include <stdio.h>
#include <vector>
#include <set>
#include <utility>

using namespace std;

#define debug(args...) fprintf(stderr, args)

vector < pair < int, int > > q;
set < pair < int, int > > s;

const int MAXN = 2e6;
int n, d, b = 0, f = 0, resp, v[MAXN];

void pushIn(int a) {
	if(q.empty()) {
		q.push_back( make_pair(a, a) );
	}
	else {
		q.push_back( make_pair(a, a + q.back().second) );
	}
}

int main() {
	scanf("%d %d", &n, &d);

	for(int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		pushIn(v[i]);
	}
	for(int i = 0; i < n/2; i++) {
		pushIn(v[i]);
	}

	while(f <= q.size()) {
		int aux, tf = 0;
		if(b-1 < 0) {
			aux = q[f].second;
		}
		else aux = q[f].second - q[b-1].second;

		//debug("aux: %d, f: %d, b-1: %d\n", aux, f, b-1);

		if(f > n) {
			tf = f - n;
		}
		if(f <= n) {
			tf = f;
		}

		if(aux == d) {
			if(s.find(make_pair(tf, b-1)) == s.end()) s.insert(make_pair(tf, b-1));
			f++;
			resp++;
		}
		else if(aux > d) {
			b++;
		}
		else {
			f++;
		}
	}

	printf("%d, %lu\n", resp,s.size());
}
