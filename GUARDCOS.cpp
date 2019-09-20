#include <stdio.h>

int d, vf, vg, pf, pg, df;
bool valid;

int main() {
	while(scanf("%d %d %d", &d, &vf, &vg) != EOF) {
		df = vg - vf;

		valid = false;

		if(d >= 12 || df <= 0) valid = false;
		pg = 0; pf = d;

		for(int i = 0; vf * i < 12; i++) {
			valid = false;
			pf += vf;
			pg += vg;

			if(pg >= pf) {
				valid = true;
				break;
			}
		}

		if(d >= 12 - df && !(d >= 12) && !(df <= 0) ) valid = true;

		if(valid) printf("S\n");
		else printf("N\n");
	}
}
