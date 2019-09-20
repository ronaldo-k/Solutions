#include <stdio.h>
#include <cmath>

using namespace std;

int main() {
	double r, l;
	scanf("%lf %lf", &r, &l);

	printf("%d\n", (int)ceil( l/(l-r) ));
}
