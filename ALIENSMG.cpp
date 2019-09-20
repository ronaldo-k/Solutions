#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

int n, resp;

string temp;
vector < string > v;
set < string > s;

int main() {
	while(true) {
		scanf("%d", &n);
		resp = n;

		if(n == 0) return 0;

		v.clear();
		s.clear();

		for(int i = 0; i < n; i++) {
			cin >> temp;
			v.push_back(temp);
		}

		for(int i = 0; i < n; i++) {
			sort(v[i].begin(), v[i].end());
		}

		for(int i = 0; i < n; i++) {
			if(s.find(v[i]) != s.end()) resp--;
			else s.insert(v[i]);
		}

		printf("%d", resp);
	}
}
