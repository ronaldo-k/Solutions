#include <stdio.h>

const int maxp = 1000000;
int casos,n,p,r,pai[maxp],prof[maxp],resp;

int find(int i) {

	if(i == pai[i]) return i;
	else return pai[i] = find(pai[i]);
	
}

void une(int a,int b) {
	
	a = find(a);
	b = find(b);
	
	if(a == b) return;
	
	if(prof[a] > prof[b]) {
		
		pai[b] = a;
		return;
		
	}
	
	pai[a] = b;
	
	if(prof[a] == prof[b]) {
		
		prof[b]++;
		return;
		
	}

	return;
}

int main() {

	scanf("%d",&casos);
	for(int i = 0; i < casos; i++) {
	
		scanf("%d%d",&p,&r);
		for(int j = 1; j <= p; j++) {
			
			pai[j] = j;
			prof[j] = 0;
			
		}
		
		resp = 0;
		for(int j = 0; j < r; j++) {
			
			int ta,tb;
			scanf("%d%d",&ta,&tb);
			if(find(ta) == find(tb)) resp++;
			else une(ta,tb);
			
		}
		printf("\n%d",resp);

	}
	
}