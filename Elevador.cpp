#include <stdio.h>
#include <math.h>

#define debug(args...) fprintf(stderr, args);

double l, c, r1, r2;

int main() {
	while(true) {
		scanf("%lf %lf %lf %lf", &l, &c, &r1, &r2);

		if(l == 0 && c == 0) break;

		if(c < (2*r1) || c < (2*r2) || l < (2*r1) || l < (2*r1)) {
			printf("N\n");
			continue;
		}

		if(c > (2*r1 + 2*r2) && l > (2*r1 + 2*r2)) {
		 	printf("S\n");
		 	continue;
		}

		// Verifica se a distancia entre os centros das duas circunferencias e
		// menor que a soma dos raios

		l -= r1 + r2;
		c -= r1 + r2;

		if(r1 + r2 <= sqrt(l*l + c*c) + 0.001) printf("S\n");
		else printf("N\n");

		//debug("rect: %f, sum = %f\n", sqrt(l*l + c*c), r1 + r2);
	}
}
