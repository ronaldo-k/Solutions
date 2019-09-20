#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int n, e;
vecotr < int > time;
vector < pair < int, int > > in;

int main() {
	scanf("%d %d", &n, &e);

	for(int i = 0; i < e; i++) {
		pair < int, int > ta;
		scanf("%d %d", &ta.first, &ta.second);
		in.push_back(ta);
	}

	sort(in.begin(), in.end());

	for(int i = 1; i < e; i++) {
		if(in[i].second == -1) time.push_back( in[i].first - in[i-1].first );
	}
	for(int i = 0; i < e-1; i++) {
		if(in[i].second == 1) time.push_back( in[i+1].first - in[i].firsst );
	}

	printf("vector time:\n");
	for(int i = 0; i < time.size(); i++) {
		printf("%d ", time[i]);
	}
	printf("\n");

	if(in[0].second == -1 || in[e].second == 1)
		time.push_back( n - in[e].first + in[0].first);
}
