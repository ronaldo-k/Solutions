#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <string.h>

using namespace std;

const int MAXN = 1010;

int n, keyAux, mark[MAXN], compNo[MAXN];

vector < int > exitSort, g[MAXN], r[MAXN];
map < string, int > key;

void dfsPreCalc(int cur) {
	mark[cur] = 1;
	
	for(int i = 0; i < g[cur].size(); i++) {
		int ngb = g[cur][i];
		
		if(mark[ngb] == 0) {
			dfsPreCalc(ngb);
		}
	}
	
	exitSort.push_back(cur);
}

void dfsComps(int cur) {
	mark[cur] = 1;
	
	for(int i = 0; i < r[cur].size(); i++) {
		int ngb = r[cur][i];
		
		if(mark[ngb] == 0) {
			dfsComps(ngb);
		}
	}
}

void keyInsert(string a, char ia) {
	string ta, fa;
	if(key.find(a) == key.end()) key.insert( make_pair(a, keyAux++) );

	if(ia != '!') {
		a = ia + a;
		ta = '!' + a;
		if(key.find(a)  == key.end()) key.insert( make_pair(a , keyAux++) );
		debug("Inserting %s -> %d\n", a.c_str());
		if(key.find(ta) == key.end()) {
			key.insert( make_pair(ta, keyAux++) );
			debug("Inserting %s -> %d\n", ta.c_str());
	}
	else {
		ta = '!' + a;
		if(key.find(a) == key.end()) key.insert( make_pair(a, keyAux++) );
		debug("Inserting %s\n", a.c_str());
		if(key.find(ta) == key.end()) key.insert( make_pair(ta, keyAux++) );
		debug("Inserting %s\n", ta.c_str());
	}
}

int main() {
	while(scanf("%d", &n) != EOF) {
		for(int i = 0; i < n; i++) {
			string sa, sb;
			char ita, itb, ta[25], tb[25];
			scanf(" %c %s %c %s", &ita, ta, &itb, tb);
						
			sa = string(ta); sb = string(tb);
			
			printf("-> %c %s %c %s\n", ita, ta, itb, tb);
			
			keyInsert(sa, ita); keyInsert(sb, itb);
		}
	}
}
