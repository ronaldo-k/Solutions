#include <stdio.h>
#include <vector>

using namespace std;

#define debug(args...) fprintf(stderr, args)
const int MAXN = 30;

vector < int > oct, qrt, sem;

int main() {
	int cur1 = 0, cur2 = 1;
	for(int i = 0; i < 8; i++) {
		int ta, tb;
		scanf("%d %d", &ta, &tb);

		if(ta > tb) oct.push_back(cur1);
		else oct.push_back(cur2);

		cur1+=2; cur2+=2;
	}

	cur1 = 0, cur2 = 1;
	for(int i = 0; i < 4; i++) {
		int ta, tb;
		scanf("%d %d", &ta, &tb);

		if(ta > tb) qrt.push_back(oct[cur1]);
		else qrt.push_back(oct[cur2]);
		cur1+=2; cur2+=2;
	}

	cur1 = 0, cur2 = 1;
	for(int i = 0; i < 2; i++) {
		int ta, tb;
		scanf("%d %d", &ta, &tb);

		if(ta > tb) sem.push_back(qrt[cur1]);
		else sem.push_back(qrt[cur2]);
		cur1+=2; cur2+=2;
	}

	int ta, tb;
	scanf("%d %d", &ta, &tb);

	if(ta > tb) printf("%c\n", sem[0] + 'A');
	else printf("%c\n", sem[1] + 'A');
	// for(int i = 0; i < 8; i++) {
	// 	debug("%d ",oct[i]);
	// }
	// debug("\n");
	// for(int i = 0; i < 4; i++) {
	// 	debug("%d ",qrt[i]);
	// }
	// debug("\n");
	// for(int i = 0; i < 2; i++) {
	// 	debug("%d ",sem[i]);
	// }
	// debug("\n");
}
