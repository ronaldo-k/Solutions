#include <stdio.h> // TEST CORNERS

int f, c, e, b;
int main() {
	scanf("%d %d %d %d", &f, &c, &e, &b);

	f -= e - 1;
	if(f * c < b) printf("PROXIMO VOO\n");
	else {
		b--;
		int aux = b % c;
		b /= c;

		printf("%d %c\n", b + e, aux + 'A');
	}
}
