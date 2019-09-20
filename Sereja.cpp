#include <stdio.h>
#include <set>
using namespace std;

const int maxn = 1e5;
int n, m, r;
int v[maxn];

int main() {
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++) {
		scanf("%d",&v[i]);
	}
	for(int i = 0; i < m; i++) {
		set < int > s;
		int ta;
		scanf("%d",&ta);
		for(int j = ta; j < n; j++) {
			s.insert(v[j]);
		}
		printf("%d",*s.size());
		/*
		for(int j = ta; j < (int)1e5; j++) {
			if(marc[j] == 1) r++;
			printf("\nm[%d] = %d",j,marc[j]);
		}
		printf("%d\n",r);
		*/
	}
}