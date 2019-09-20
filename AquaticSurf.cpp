// CODE

#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>

#define debug(args...) fprintf(stderr, args)
using namespace std;

stack < pair < int, int > > min1, min2, max1, max2;
vector < int > v;

int n, b;

// MIN QUEUE

void insertMin(int a) {
	if(min1.empty()) min1.push( make_pair(a, a) );
	else min1.push( make_pair(a, min(min1.top().second, a)) );
}

int minimum() {
	if(min1.empty()) return min2.top().second;
	if(min2.empty()) return min1.top().second;
	return min(min1.top().second, min2.top().second);
}

void removeMin() {
	if(min2.empty()) { //debug("in removeMin(): min1: %d, min2: %d\n", (int)min1.size(), (int)min2.size());
		int s = min1.size();
		for(int i = 0; i < s; i++) {
			int ta = min1.top().first;

			debug("27: ta: %d is now in min2\n", ta);
			debug("28: minimum: %d\n", minimum());

			if(i == 0) min2.push( make_pair(ta, ta) );
			else min2.push( make_pair(ta, min(min2.top().second, ta)) );

			min1.pop();
		}
	}

	min2.pop();
}

//----------------------------------------------------------------------------//

// MAX QUEUE

// void insertMax(int a) {
// 	if(max1.empty()) max1.push( make_pair(a, a));
// 	else max1.push( make_pair(a, max(max1.top().second, a)) );
// }
//
// void removeMax() {
// 	if(max2.empty()) {
// 		for(int i = 0; i < max1.size(); i++) {
// 			int ta = max1.top().first;
// 			max1.pop();
//
// 			max2.push( make_pair(ta, max(max2.top().second, ta)));
// 		}
// 	}
//
// 	max2.pop();
// }
//
// int maximum() {
// 	if(max1.empty()) return max2.top().second;
// 	if(max2.empty()) return max1.top().second;
// 	return max(max1.top().second, max2.top().second);
// }

//----------------------------------------------------------------------------//

int main() {
	scanf("%d %d", &n, &b);
	int ini = 0, fim = b - 1, sum = 0;

	for(int i = 0; i < n; i++) {
		int ta;
		scanf("%d", &ta);
		v.push_back(ta);
	}

	for(int i = 0; i < b-1; i++) {
		insertMin(v[i]);
		sum += v[i];
		debug("88: sum before:%d, sum now: %d, value added: %d\n", sum - v[i], sum, v[i]);
	}

	for(int i = 0; i < n - b + 1; i++) {
		insertMin(v[fim]);

		sum += v[fim];
		debug("96: sum before: %d, now: %d, later: %d\n -> min: %d\n", sum-v[fim], sum, sum - minimum(), minimum());
		sum -= minimum();

		sum -= v[ini];
		ini++; fim++;
	}

	printf("%d\n", sum);
}
