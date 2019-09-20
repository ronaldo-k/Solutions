#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXN = 1e5;
int n, v[MAXN], dist[MAXN], lz = -1, fz = MAXN;
int main() {
	scanf("%d\n", &n);

	for(int i = 0; i < n; i++) {
		scanf("%d", &v[i]);

		if(v[i] == 0) {
			dist[i] = 0;
			fz = min(fz, i);
			lz = max(lz, i);
		}
		else dist[i] = 9;
	}

	int last = -1;
	for(int i = fz; i < lz; i++) {
		if(v[i] == 0) {
			dist[i] = 0;
			last = i;
		}
		else if(last == -1) {
			dist[i] = 9;
		}
		else {
			dist[i] = min(9, i - last);
		}
	}

	last = n;
	for(int i = lz; i >= fz; i--) {
		if(v[i] == 0) {
			dist[i] = 0;
			last = i;
		}
		else {
			dist[i] = min(dist[i], last - i);
		}
	}

	for(int i = lz; i < n; i++) {
		dist[i] = min(9, i - lz);
	}
	for(int i = fz; i >= 0; i--) {
		dist[i] = min(9, fz - i);
	}

	for(int i = 0; i < n; i++) {
		if(i < n-1) printf("%d ", dist[i]);
		else printf("%d", dist[i]);
	}
}
