// Small to Large - ADAGRAFT (https://www.spoj.com/problems/ADAGRAFT/)

#include <stdio.h>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define debug(args...) fprintf(stderr, args);

const int MAXN = 1e5 + 10;

/*
Variáveis:
n      : Número de vértices,
t      : "Cronômetro" da DFS precalc().
st[i]  : Armazena o tempo em que precalc() entrou no vértice i.
ft[i]  : Armazena o tempo em que precalc() saiu no vértice i.
inv[t] : Vetor de marcação inverso do st[i]. inv[t] guarda o nó onde precalc() entrou no tempo t.
col[i] : Guarda a cor de i. (ENTRADA)
diff[i]: Guarda a quantidade de cores distintas na subárvore de i.
cnt[i] : Count da DFS Small to Large.
*/

int n, t;
int sub[MAXN], st[MAXN], ft[MAXN], inv[MAXN], col[MAXN], diff[MAXN];
long long int cnt[MAXN];

vector < int > g[MAXN];

void precalc(int cur, int par) {
	t++;
	
	sub[cur] = 1;
	st[cur] = t;
	inv[t] = cur;
	
	for(int i = 0; i < g[cur].size(); i++) {
		int ngb = g[cur][i];
		
		if(par != ngb) {
			precalc(ngb, cur);
			sub[ngb] += sub[cur];
		}
	}
	
	ft[cur] = t;
	
	debug("%d -> sub = %d, st = %d, ft = %d\n", cur, sub[cur], st[cur], ft[cur]);
}

void dfs(int cur, int par, bool keep) {
	debug("cur = %d, par = %d, keep = %d\n", cur, par, keep);
	// s: Stores which are the different colours found.
	
	set < int > s;
	
	int maxSub = -1, bigChild = -1;
	
	for(int i = 0; i < g[cur].size(); i++) {
		int ngb = g[cur][i];
		
		if(par != ngb && sub[ngb] > maxSub) {
			maxSub = sub[ngb];
			bigChild = ngb;
		}
	}
	
	debug("%d -> bigChild decided as %d\n", cur, bigChild);
	
	for(int i = 0; i < g[cur].size(); i++) {
		int ngb = g[cur][i];
		
		if(par != ngb && ngb != bigChild) {
			debug("%d -> calling DFS to %d\n", cur, ngb);
			dfs(ngb, cur, 0);
		}
	}
	
	if(bigChild == -1) return;
	
	debug("%d -> calling DFS to bigChild\n", cur);
	dfs(bigChild, cur, 1);
	
	debug("%d -> actually calculating the values of cnt\n", cur);
	for(int i = 0; i < g[cur].size(); i++) {
		int ngb = g[cur][i];
		
		if(par != ngb)
			for(int j = st[ngb]; j <= ft[ngb]; i++) {
				cnt[ col[inv[j]] ]++;
				s.insert(col[inv[j]]);
			}
	}
	
	cnt[col[cur]]++;
	s.insert(col[cur]);
	
	// Query:
	
	diff[cur] = s.size();
	
	if(!keep) {
		for(int j = st[cur]; j <= ft[cur]; j++) {
			cnt[ col[inv[j]] ]--;
		}
	}
	debug("(%d, %d, %d) reached the end\n", cur, par, keep);
}

int main() {
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++) {
		scanf("%d", &col[i]);
	}
	
	for(int i = 1; i < n; i++) {
		int ta, tb;
		scanf("%d %d", &ta, &tb);
		
		g[ta].push_back(tb);
		g[tb].push_back(ta);
	}
	
	precalc(1, 1);
	
	dfs(1, 1, false);
	
	for(int i = 1; i <= n; i++) {
		debug("%d -> %d\n", i, diff[i]);
	}
}
