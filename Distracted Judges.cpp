// DP – Distracted Judges (SPOJ – TAP2014J)
// Made in: 17/06/2019

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 10;

int n, in[MAXN], dp[MAXN];
vector < int > ans;

void makeBase() {
	dp[n+1] = 1;
}

void solve() {
	for(int i = n; i >= 1; i--) {
		if(in[i] + i <= n) dp[i] = dp[i + in[i] + 1];
	}
}

void getAnswer() {
	for(int i = 2; i <= n + 1; i++) {
		if(dp[i] == 1) ans.push_back(i - 1);
	}

	sort(ans.begin(), ans.end());

	for(int i = 0; i < ans.size(); i++) {
		printf("%d\n", ans[i]);
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &in[i]);
	}

	makeBase();
	solve();
	getAnswer();
}
