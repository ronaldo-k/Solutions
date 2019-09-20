#include <stdio.h>

long long int n, k, maior;
int main() {
	scanf("%lld %lld", &n, &k);

	maior = n - (k - 1);

	printf("%lld\n", (maior * maior) + k - 1);
}
