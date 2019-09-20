// GREEDY ALGORITHM – Prosjek (oj.uz)
// Made on: 26/08/2019

#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXN = 30;
int n;
double v[MAXN];

int main() {
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		scanf("%lf", &v[i]);
	}

	sort(v, v + n);

	for(int i = 1; i < n; i++) {
		v[i] = (v[i] + v[i-1])/2;
	}

	printf("%.6lf\n", v[n-1]);
}
