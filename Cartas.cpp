// AD-HOC – Cartas (OBI)
// 08/09/2019

#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXN = 10;
bool isCresc, isDecresc;
int v[MAXN], s[MAXN];

int main() {
	isCresc = true;
	isDecresc = true;

	for(int i = 0; i < 5; i++) {
		scanf("%d", &v[i]);
		s[i] = v[i];
	}

	sort(s, s + 5);

	for(int i = 0; i < 5; i++) {
		if(s[i] != v[i]) {
			isCresc = false;
			break;
		}
	}

	for(int i = 0; i < 5; i++) {
		if(s[5-(i+1)] != v[i]) {
			isDecresc = false;
			break;
		}
	}

	if(isCresc) printf("C\n");
	else if(isDecresc) printf("D\n");
	else printf("N\n");
}
