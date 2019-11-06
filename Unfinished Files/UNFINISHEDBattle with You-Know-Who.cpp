/*
Test the following case:
20 62
L 1 L 2 L 3 L 4 L 5 L 6 L 7 L 8 L 9 L 10 L 11 L 12 L 13 L 14 L 15 L 16 L 17 L 18 L 19 L 20
D 5
L 1 L 2 L 3 L 4 L 5 L 6 L 7 L 8 L 9 L 10 L 11 L 12 L 13 L 14 L 15 L 16 L 17 L 18 L 19 L 20
D 5
L 1 L 2 L 3 L 4 L 5 L 6 L 7 L 8 L 9 L 10 L 11 L 12 L 13 L 14 L 15 L 16 L 17 L 18 L 19 L 20
*/

#include <stdio.h>
#include <vector>

using namespace std;

#define debug(args...) fprintf(stderr, args)

int n, m;
vector < int > sum, e, d;

int create(int beg, int fin) {
	sum.push_back(fin - beg + 1);
	e.push_back(-1);
	d.push_back(-1);
	return sum.size() - 1;
}

void update(int pos, int beg, int fin, int id, int val) {
	if(id < beg || id > fin) return;
	if(beg == fin) {
		sum[pos] += val;
		return;
	}

	int m = (beg + fin) / 2;

	if(id <= m) {
		if(e[pos] == -1) {
			int aux = create(beg, m);
			e[pos] = aux;
		}
		update(e[pos], beg, m, id, val);
	}
	else {
		if(d[pos] == -1) {
			int aux = create(m+1, fin);
			d[pos] = aux;
		}
		update(d[pos], m+1, fin, id, val);
	}

	int sumE = (e[pos] == -1) ? (m - beg + 1) : sum[e[pos]];
	int sumD = (d[pos] == -1) ? (fin - m+1 + 1) : sum[d[pos]];

	sum[pos] = sumE + sumD;
}

int binarySearch(int pos, int beg, int fin, int amt) {
	// Returns the first index where the amount of 1s between 1 and amt
	// (inclusive) is greater or equal to amt.
	
	if(pos == -1) {
		//debug("[BS] Returning %d + %d - 1 = %d\n", beg, amt, beg + amt - 1);
		return beg + amt - 1;
	}
	
	if(beg == fin) return beg;

	int sumE = (e[pos] == -1) ? (m - beg + 1) : sum[e[pos]];
	int m = (beg + fin) / 2;

	if(beg == fin - 1) m = beg;

	if(sumE >= amt) {
		if(e[pos] != -1) return binarySearch(e[pos], beg, m, amt);
		return beg + amt - 1;
	}
	else {
		if(d[pos] != -1) return binarySearch(d[pos], m+1, fin, amt - sumE);
		return m+1 + (amt - sumE) - 1;
	}
}

//int fixBinarySearch(int pos, int beg, int fin, int id) {
//	int id1 = binarySearch(1, 1, n, id);
//	int id2 = binarySearch(1, 1, n, id-1);
//	
//	if(id2 > id1) id1 += 2;
//	
//	return id1;
//}

int main() {
	scanf("%d %d", &n, &m);
	create(0, -1);
	create(1, n);

	for(int i = 1; i <= m; i++) {
		char top; int ta;
		scanf(" %c %d", &top, &ta);
		if(top == 'D') {
			int id = binarySearch(1, 1, n, ta);
			update(1, 1, n, id, -1);
		}
		else {
			printf("%d\n", binarySearch(1, 1, n, ta));
		}
	}
}
