#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct point {
	int x, y;

	struct point operator-(struct point a) {
		struct point aux;

		aux.x = x - a.x;
		aux.y = y - a.y;

		return aux;
	}

};

vector < struct point > in, upper, lower;

bool comp(struct point a, struct point b) {
	if(a.x == b.x) return a.y < b.y;

	return a.x < b.x;
}

int cross(struct point a, struct point b) {
	return (a.x * b.y) - (a.y * b.x);
}

//\/\\//\\\\\/\//////\/\/////\\//////////\/\//\/\/\//\\\\\\////\\\/////\/\\\\\\\

int main() {
	int n;
	while (true) {
		in.clear(); upper.clear(); lower.clear();

		scanf("%d", &n);
		if(n == 0) break;

		for(int i = 0; i < n; i++) {
			struct point aux;
			scanf("%d %d", &aux.x, &aux.y);

			in.push_back(aux);
		}

		sort(in.begin(), in.end(), comp);

		int t = -1;
		for(int i = 0; i < in.size(); i++) {
			if(i > 0 && in[i].x == in[i-1].x && in[i].y == in[i-1].y) {
				continue;
			}

			while( t >= 1 && cross( upper[t] - upper[t-1], in[i] - upper[t-1] ) >= 0) {
				t--;
				upper.pop_back();
			}

			t++;
			upper.push_back(in[i]);
		}

		t = -1;
		for(int i = 0; i < in.size(); i++) {
			if(i > 0 && in[i].x == in[i-1].x && in[i].y == in[i-1].y) {
				continue;
			}

			while( t >= 1 && cross( lower[t] - lower[t-1], in[i] - lower[t-1] ) <= 0) {
				t--;
				lower.pop_back();
			}

			t++;
			lower.push_back(in[i]);
		}

		int resp = lower.size() + upper.size() - 2;
		if(resp == 0) resp++;

		printf("%d\n",resp);

		for(int i = upper.size() - 1; i >= 0; i--) {
			struct point cur = upper[i];
			printf("%d %d\n", cur.x, cur.y);
		}

		for(int i = 1; i <= (int)lower.size() - 2; i++) {
			if((int)lower.size() - 2 <= 0) break;
			//fprintf(stderr, "L: i = %d, lower size = %d\n", i, lower.size());

			struct point cur = lower[i];
			printf("%d %d\n", cur.x, cur.y);
		}
	}
}
