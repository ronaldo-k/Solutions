#include <stdio.h>

int l, c, l1, l2;
int main() {
	scanf("%d %d", &l, &c);

	l1 = (l*c) + ((l-1) * (c-1));
	l2 = ( ((l-1)*2) + ((c-1)*2) );

	printf("%d \n%d \n", l1, l2);
}
