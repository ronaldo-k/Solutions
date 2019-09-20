#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

bool valid;
int n;
vector < int > v;

int main() {
	valid = true;
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		int ta;
		scanf("%d", &ta);
		v.push_back(ta);
	}

	sort(v.begin(), v.end());

	if(v[0] > 8) valid = false;

	for(int i = 0; i < n-1; i++) {
		if(v[i+1] - v[i] > 8) valid = false;
	}

	if(valid) printf("S\n");
	else printf("N\n");
}
