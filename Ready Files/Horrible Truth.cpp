// PATTERN RECOGNITION + I/O WITH FILES - Horrible Truth
// (Codeforces 2010-11 ACM-ICPC Northern Subregional)

/*
WARNING: This problem has a non-standard input method.

The input is given through a file called "horrible.in", and its correspondent
output is shown in "horrible.out".

freopen(C string filename, char mode, buffer B) is a function from stdio.h
which opens a file called filename so it can be modified in buffer B. mode
should be "r" to read from filename and "w" to write to filename.
*/

#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;

const int MAXN = 110;

bool mrk[MAXN];
int n;

vector < pair < int, int > > ans;

int main() {
	freopen("horrible.in", "r", stdin);
	freopen("horrible.out", "w", stdout);
	
	scanf("%d", &n);
	
	if(n == 1) {
		printf("1\n1 0\n");
		return 0;
	}

	ans.push_back(make_pair(n, -1));
	
	for(int i = 1; i <= n-1; i++) {
		ans.push_back(make_pair(i, 0));
		mrk[i] = true;
		
		for(int j = 1; j <= n; j++) {
			if(j != i)
				ans.push_back(make_pair(j, i));
			if(j != i+1)
				ans.push_back(make_pair(j, -(i+1)));
		}
	}

	ans.push_back(make_pair(n, 0));
	ans.push_back(make_pair(1, n));
	
	for(int i = 0; i < ans.size()-1; i++) {
		if(ans[i].second > 0 && ans[i+1].second < 0)
			swap(ans[i], ans[i+1]), i++;
	}
	
	printf("%d\n", ans.size());
	for(int i = 0; i < ans.size(); i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
}
