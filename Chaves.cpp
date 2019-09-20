#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

long long int n, b; bool ok = false;
int main() {
	scanf("%lld", &n);

	for(int i = 0; i < n; i++) {
		char now[300];
		if(scanf(" %[^\n]", now) == EOF) break;

		for(int j = 0; j < sizeof(now); j++) {
			if(now[j] == '{') {
				ok = true;
				b++;
			}
			else if(now[j] == '}' && ok == true) {
				b--;
			}
			//printf(" >> b = %lld\n", b);
		}
	}

	if(b == 0) printf("S\n");
	else printf("N\n");
}
