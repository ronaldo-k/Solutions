#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

const int MAXN = 1e5;
map < int, string > in;
vector < string > m[MAXN];

int main() {
	int n, t;

	scanf("%d %d", &n, &t);

	for(int i = 0; i < n; i++) {
		int ta;
		string temp;

		cin >> temp;
		scanf("%d", &ta);

		in.insert(make_pair(ta, temp));
	}

	int teamCount = 0;
	map < int, string > :: iterator it = in.end();
	it--;

	for(; it != in.begin(); it--) {
		cout << it->second << "\n";
	}
	/*
	for(; it != in.begin(); it--) {
		m[teamCount].push_back(it->second);
		cout << it->second << " " << teamCount << "\n";

		teamCount++;
		if(teamCount >= t) teamCount = 0;
	}

	for(int i = 0; i < t; i++) {
		sort(m[i].begin(), m[i].end());
	}

	for(int i = 0; i < t; i++) {
		printf("Time %d\n", i+1);

		for(int j = 0; j < m[i].size(); j++) {
			cout << m[i][j] << "\n";
		}
		printf("\n");
	}
	*/
}
