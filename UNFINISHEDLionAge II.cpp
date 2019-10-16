#include <stdio.h>
#include <map>

using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAXN = 110;

char s[MAXN];

int k, n, dp[MAXN][MAXN];

map < pair < char, char > , int > m;

int main() {
	scanf(" %s %d", s, &k);
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++) {
		char ta, tb;
		int tw;
		scanf(" %c %c %d", &ta, &tb, &tw);
		m.insert( make_pair(make_pair(ta, tb), tw) );
	}
}
