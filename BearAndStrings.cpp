#include <stdio.h>
#include <iostream>
#include <deque>
#include <string>

using namespace std;

int resp, total;
string strIn;
deque < int > dqBear;

int main() {
	cin >> strIn;

	for(int i = 0; i < strIn.size() - 3; i++) {
		if(strIn[i] == 'b' && strIn[i+1] == 'e' && strIn[i+2] == 'a' && strIn[i+3] == 'r') {
			// If there is a substring "bear" starting in strIn[i]

			dqBear.push_back(i);
			printf("There's a \"bear\" beggining at %d\n", i);
		}
	}
	dqBear.push_back(strIn.size());
	for(int i = 0; i < strIn.size(); i++) {
		total += strIn.size() - i;
	}

	printf("Total = %d\n", total);


	for(int i = 0; i < strIn.size() - 1; i++) {
		if(i == dqBear.front()) {
			dqBear.pop_front();
			continue;
		}

		for(int j = i+1; j < strIn.size(); j++) {
			if(j >= dqBear.front() + 2) break;

			printf("(%d, %d)\n", i, j);
			resp++;
		}
	}

	printf("-> %d", resp);
}
