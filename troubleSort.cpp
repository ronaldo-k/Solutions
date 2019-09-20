#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector < int > v, t, o, e;
queue < int > odd, even;

const int MAXN = 1e5;
int teste, n;

int main() {
	scanf("%d", &teste);

	for(int casosde = 0; casosde < teste; casosde++) {
		scanf("%d", &n);

		v.clear(); t.clear(); o.clear(); e.clear();

		while( !(odd.empty()) ) odd.pop();
		while( !(even.empty()) ) even.pop();

		for(int i = 0; i < n; i++) {
			int ta;
			scanf("%d", &ta);
			v.push_back(ta);

			if(i % 2 == 0) o.push_back(ta);
			else e.push_back(ta);
		}

		sort(v.begin(), v.end());
		sort(o.begin(), o.end());
		sort(e.begin(), e.end());

		for(int i = 0; i < o.size(); i++) {
			odd.push(o[i]);
		}

		for(int i = 0; i < e.size(); i++) {
			even.push(e[i]);
		}

		for(int i = 0; i < n; i++) {
			if(i % 2 == 0) {
				t.push_back(odd.front());
				odd.pop();
			}
			else {
				t.push_back(even.front());
				even.pop();
			}
		}

		bool p = false;
		printf("Case #%d: ", casosde + 1);
		for(int i = 0; i < n; i++) {
			if(t[i] != v[i]) {
				printf("%d\n", i);
				p = true;
				break;
			}
		}

		if(p == false) printf("OK\n");
	}
}
