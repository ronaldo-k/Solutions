#include <stdio.h>
#include <vector>
using namespace std;

const int maxn = 110;
vector <int> grafo[maxn];
int c,pai[maxn],prof[maxn];

int find(int a) {
	if(pai[a] == a) return a;
	else return pai[a] = find(pai[a]);
}

void une(int a, int b) {
	a = find(a);
	b = find(b);
	
	if(a == b) return;
	
	else if(prof[a] > prof[b]) pai[b] = a;
	pai[a] = b;
	if(prof[a] == prof[b]) prof[a]++;
	return;
}

int main() {
	while(true) {
		c++;
		int n, m, a;
		scanf("%d%d",&n,&m);
		for(int i = 0; i < n; i++) {
			prof[i] = 0;
			pai[i] = i;
			grafo[i].clear();
			a = 0;
		}
		for(int i = 0; i < m; i++) {
			int ta, tb;
			scanf("%d%d",&ta,&tb);
			if(find(ta) != find(tb)) {
				une(ta,tb);
			}
			else {
				a++;
				break;
			}
		}
		if(a == 0) printf("Instancia %d = sim",c);
		else printf("Instancia %d = nao",c);
	}
}