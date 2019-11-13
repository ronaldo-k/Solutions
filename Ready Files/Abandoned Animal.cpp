// COMPARING MULTIPLE POSSIBLE ANSWERS - Abandoned Animal (Kattis BAPC Preliminaries 2017)

#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAXN = 1e5 + 10;

bool isUnique = true;
int n, k, m, cnt;

vector < int > in, ansSTL, ansLTS;
set < int > s[MAXN];
map < string, int > cor;

int main() {
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i < k; i++) {
		char ts[20];
		int tid;
		scanf("%d %s", &tid, ts);

		if(cor.find(ts) == cor.end()) 
			cor.insert( make_pair(ts, ++cnt) );
			
		s[tid].insert(cor[ts]);
	}
	
	scanf("%d", &m);
	
	for(int i = 0; i < m; i++) {
		char ts[20];
		scanf(" %s", ts);
		
		in.push_back(cor[ts]);
	}
	
	// Search in a lexicographically crescent manner
	int curId = 0;
	
	for(int i = 0; i < m && curId < n; i++) {
		set < int > :: iterator it;
		it = s[curId].lower_bound(in[i]);
		
		if(*it == in[i]) ansSTL.push_back(curId);
		else curId++, i--;
	}
	
	// Search in a lexicographically decrescent manner
	curId = n-1;
	
	for(int i = m-1; i >= 0 && curId >= 0; i--) {
		set < int > :: iterator it;
		it = s[curId].lower_bound(in[i]);
		
		if(*it == in[i]) ansLTS.push_back(curId);
		else curId--, i++;
	}
	
	if(ansSTL.size() < m) {
		printf("impossible\n");
		return 0;
	}

	for(int i = 0; i < m; i++) {
		if(ansSTL[i] != ansLTS[m-(i+1)]) {
			isUnique = false;
			break;
		}
	}
	
	if(isUnique) printf("unique\n");
	else printf("ambiguous\n");
}
