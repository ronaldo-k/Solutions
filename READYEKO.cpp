// BINARY SEARCH - EKO (SPOJ COCI 2011/12)

#include <stdio.h>
#include <algorithm>

using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAXN = 1e6 + 10;

int n, t, v[MAXN];
long long int s[MAXN];

int binarySearch() {
	long long int ini = 1, fim = (int)1e9;
	
	while(ini < fim) {
		long long int m = (ini + fim) / 2;
		
		int ts = upper_bound(v, v+n, m) - v;
		
		if(s[n-1] - s[ts-1] - m*(n-ts) >= t) ini = m+1;
		else fim = m;
	}
	
	return fim;
}

int main() {
	scanf("%d %d", &n, &t);
	
	for(int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	
	sort(v, v + n);
	
	for(int i = 0; i < n; i++) {
		if(i == 0) s[i] = v[i];
		else s[i] = v[i] + s[i-1];
	}
	
	int ans = binarySearch();
	
	printf("%d\n", ans-1);
}
