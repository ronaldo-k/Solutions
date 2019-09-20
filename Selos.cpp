#include <stdio.h>
#include <math.h>

using namespace std;

long long int n;

int main() {
	scanf("%lld", &n);

	for(int i = 2; i <= (int)sqrt(n)+1; i++) {
		if(n % i == 0) {
			printf("S\n");
			return 0;
		}
	}

	printf("N\n");
}
