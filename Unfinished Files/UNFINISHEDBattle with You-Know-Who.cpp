#include <stdio.h>
#include <vector>

using namespace std;

#define debug(args...) fprintf(stderr, args)

int n, m;
vector < int > sum, e, d;

void printcur() {
	debug("-----------------------------------------\n");
	debug("! CURRENT STATE: \n");
	for(int i = 0; i < sum.size(); i++) {
		debug("i = %d | sum = %d | e = %d | d = %d\n", i, sum[i], e[i], d[i]);
	}
	debug("-----------------------------------------\n");
}

int create(int beg, int fin) {
	sum.push_back(fin - beg + 1);
	e.push_back(-1);
	d.push_back(-1);
	int tid = sum.size()-1;
	debug("[sum = %d, e = %d, d = %d, id = %d\n", sum[tid], e[tid], d[tid], tid);
	return sum.size() - 1;
}

void update(int pos, int beg, int fin, int id, int val) {
	//debug("UPDATE: pos = %d, beg = %d, fin = %d, id = %d, val = %d\n", pos, beg, fin, id, val);
	if(id < beg || id > fin) return;
	if(beg == fin) {
		sum[pos] += val;
		return;
	}

	int m = (beg + fin) / 2;

	printcur();

	if(id <= m) {
		if(e[pos] == -1) {
			int aux = create(beg, m);
			e[pos] = aux;
		}
		update(e[pos], beg, m, id, val);
		printcur();
	}
	else {
		if(d[pos] == -1) {
			int aux = create(m+1, fin);
			d[pos] = aux;
		}
		update(d[pos], m+1, fin, id, val);
		printcur();
	}

	int sumE = (e[pos] == -1) ? (m - beg + 1) : sum[e[pos]];
	debug("sumE = %d, e[pos] = %d\n", sumE, e[pos]);
	int sumD = (d[pos] == -1) ? (fin - m+1 + 1) : sum[d[pos]];
	debug("sumD = %d, d[pos] = %d\n", sumD, d[pos]);

	printcur();
	sum[pos] = sumE + sumD;
}

int binarySearch(int pos, int beg, int fin, int amt) {
	debug(" > BS: pos = %d | beg = %d | fin = %d | amt = %d\n", pos, beg, fin, amt);

	// Returns the first index where the amount of 1s between 1 and amt
	// (inclusive) is greater or equal to amt.

	if(beg == fin) return beg;

	debug(" > BS: e = %d, d = %d, sum = %d -> ", e[pos], d[pos], sum[pos]);
	int sumE = (e[pos] == -1) ? (m - beg + 1) : sum[e[pos]];
	int sumD = (d[pos] == -1) ? (fin - m+1 + 1) : sum[d[pos]];
	//debug("sum[e[%d] = %d] = %d = %d\n", pos, e[pos], sumE, sum[e[pos]]);
	int m = (beg + fin) / 2;

	if(beg == fin - 1) m = beg;

	if(sumE >= amt) {
		debug("(could go left ... ");
		if(e[pos] != -1) {
			debug("(going left)\n");
			int tans = binarySearch(e[pos], beg, m, amt);
			debug("Returning %d\n", tans);
			return tans;
		}
	}
	else {
		debug("(could go right as %d < %d ... ", sumE, amt);
		if(d[pos] != -1) {
			debug("going right)\n");
			int tans = binarySearch(d[pos], m+1, fin, amt - sumE);
			debug("Returning %d\n", tans);
			return tans;
		}
		return sumE - beg + 1;
	}

	debug("(stopping)\n");
	return amt - beg + 1;
}

int main() {
	scanf("%d %d", &n, &m);
	create(0, -1);
	create(1, n);

	for(int i = 1; i <= m; i++) {
		char top; int ta;
		scanf(" %c %d", &top, &ta);
		if(top == 'D') {
			int id = binarySearch(1, 1, n, ta);
			//debug("|| id = %d\n", id);
			update(1, 1, n, id, -1);
		}
		else {
			printf("%d\n", binarySearch(1, 1, n, ta));
		}
	}
}
