#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct comp {
	int a, b, c;
};

const int MAXN = 1e5;
const int INF = 2e9;
int casos, n, seg[4 * MAXN], v1[MAXN];
vector < comp > v;

bool cmp (struct comp ta, struct comp tb) {
	return ta.a < tb.a; //!
}

void update(int pos, int ini, int fim, int id, int val) {
	if(ini > id || fim < id) return;
	if(ini == fim) {
		seg[pos] = val;
		return;
	}
	
	int m = (ini+fim)/2;
	int e = 2*pos,d = e + 1;
	
	update(e,ini,m,id,val);
	update(d,m+1,fim,id,val);
	
	seg[pos] = min(seg[e],seg[d]);
}

int query(int pos, int ini, int fim, int p, int q) {
	if(p > fim || q < ini) return INF;
	if(ini >= p && fim <= q) {
		return seg[pos];
	} 
	
	int m = (ini+fim)/2;
	int e = 2 * pos,d = e + 1;
	
	return min(query(e, ini, m, p, q), query(d, m+1, fim, p, q));
}

int main() {
	scanf("%d",&casos);
	for(int z = 0; z < casos; z++) {
		scanf("%d",&n);
		for(int i = 1; i <= n; i++) {
			struct comp aux;
			int ta, tb, tc;
			scanf("%d%d%d",&ta,&tb,&tc);
			aux.a = ta; aux.b = tb; aux.c = tc;
			v.push_back(aux);
			v1[tb] = tc;
		}
		sort(v.begin(),v.end(),cmp);
		for(int i = 1; i <= 4*MAXN; i++) {
			seg[pos] = INF;
		}
		for(int i = 1; i <= n; i++) {
			if(query(1,1,n,1,i-1) > v1[i]) {
				resp++;
			}
		}
		printf("%d\n",resp);
	}
}