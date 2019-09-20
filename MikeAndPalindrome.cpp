#include <stdio.h>
#include <string>

using namespace std;

int resp;
char in[20];
string s;

int main() {
	scanf(" %s", in);

	s = (string)in;

	for(int i = 0; i < s.size() / 2; i++) {
		int ini = i, fim = s.size() - i - 1;

		if(s[ini] != s[fim]) resp++;
	}

	if(s.size() % 2 == 1 && resp == 0) resp = 1;

	if(resp == 1) printf("YES\n");
	else printf("NO\n");
}
