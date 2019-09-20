#include <stdio.h>

const int maxn = 70;
int n;
int m[maxn][maxn];


int main() {
	scanf("%d",&n);
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			m[j][i] = 0;
		}
	}
	
	for(int i = 0; i < n; i++) {
		scanf("%d",&m[i][0]);
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(m[j][i] != 0 && m[j+1][i] != 0) {
				if(m[j][i] == m[j+1][i]) m[j][i+1] = 1;
				else if(m[j][i] != m[j+1][i]) m[j][i+1] = -1;
			}
		}
	}
	if(m[0][n-1] == 1) printf("preta");
	else if(m[0][n-1] == -1) printf("branca");
	return 0;
}