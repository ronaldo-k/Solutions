// VECTOR PRODUCT, SUM AND SUBTRACTION – Completing the Square (Kattis BAPC Preliminaries 2016)

#include <stdio.h>

struct point {
	int x, y;

	point(int tx = 0, int ty = 0) {
		x = tx, y = ty;
	}
	struct point operator+(struct point b) {
		struct point aux;
		aux.x = x + b.x;
		aux.y = y + b.y;
		return aux;
	}
	struct point operator-(struct point b) {
		struct point aux;
		aux.x = x - b.x;
		aux.y = y - b.y;
		return aux;
	}
};

struct point a, b, c;

int dot(struct point a, struct point b) {
	return (a.x * b.x) + (a.y * b.y);
}

int main() {
	scanf("%d %d %d %d %d %d", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);

	struct point p;
	if( dot(b-a, c-a) == 0 ) {
		p = b + (c - a);
	}
	else if( dot(a-b, c-b) == 0 ) {
		p = a + (c - b);
	}
	else if( dot(a-c, b-c) == 0 ) {
		p = a + (b - c);
	}

	printf("%d %d\n", p.x, p.y);
}
