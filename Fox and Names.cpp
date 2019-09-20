// Ordenacao topologica + strings - Fox and Names (Codeforces)

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <string.h>

using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAXN = 300;

int n, inDeg[MAXN], marc[MAXN];
vector < string > v;
vector < char > g[MAXN], resp;
set < char > q;

int main() {
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		char ta[MAXN]; string sa;
		scanf("%s", ta);
		sa = (string)ta;

		v.push_back(sa);
	}

	for(int i = 0; i < n-1; i++) {
		bool samePrefix = false;
		string ta = v[i], tb = v[i+1];

		for(int j = 0; j < min(ta.size(), tb.size()); j++) {
			//debug(" ———> %c %c\n", ta[j], tb[j]);
			if(ta[j] < tb[j]) {
				g[ta[j]].push_back(tb[j]);
				inDeg[tb[j]]++; //debug("inDeg[%c]++\n", tb[j]);
				samePrefix = false;
				break;
			}
			else if(ta[j] > tb[j]) {
				g[ta[j]].push_back(tb[j]);
				inDeg[tb[j]]++; //debug("inDeg[%c]++\n", tb[j]);
				samePrefix = false;
				break;
			}
			else samePrefix = true;
		}

		if(samePrefix) {
			if(ta.size() > tb.size()) {
				printf("Impossible\n");
				return 0;
			}
		}
	}

	for(char i = 'a'; i <= 'z'; i++) {
		if(inDeg[i] == 0) {
			marc[i] = 1;
			q.insert(i);
		}
	}

	while(!q.empty()) {
		int cur = *q.begin(); q.erase(cur);
		resp.push_back(cur);

		for(int i = 0; i < g[cur].size(); i++) {
			int ngb = g[cur][i];

			inDeg[ngb]--;
			if(inDeg[ngb] == 0 && marc[ngb] == 0) {
				marc[ngb] = 1;
				q.insert(ngb);
			}
		}
	}

	for(char i = 'a'; i < 'z'; i++) {
		if(marc[i] == 0) {
			printf("Impossible\n");
			return 0;
		}
	}

	for(int i = 0; i < resp.size(); i++) {
		printf("%c", resp[i]);
	}
	printf("\n");
}
