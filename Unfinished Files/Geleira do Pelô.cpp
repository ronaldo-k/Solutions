#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <set>

using namespace std;

#define debug(args...) //fprintf(stderr, args)

struct point {
	int x, y;
	
	point(int tx = 0, int ty = 0) {
		x = tx; y = ty;
	}
};

struct pointEvent {
	int op;
	struct point p;
	
	pointEvent(struct point tp = point(0, 0), int top = 0) {
		p = tp; op = top;
	}
};

const int MAXN = 1e5 + 10;

int n;
vector < int > tempX, tempY;
set < int > mx, my;
vector < struct point > v[MAXN];
vector < struct pointEvent > in;

bool sortByX(struct pointEvent a, struct pointEvent b) {
	if(a.p.x == b.p.x) return a.p.y < b.p.y;
	else return a.p.x < b.p.x;
}

bool sortByY(struct pointEvent a, struct pointEvent b) {
	if(a.p.y == b.p.y) return a.p.x < b.p.x;
	else return a.p.y < b.p.y;
}

int main() {
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++) {
		int tn;
		scanf("%d", &tn);
		
		for(int j = 0; j < tn; j++) {
			struct point t;
			scanf("%d %d", &t.x, &t.y);
			v[i].push_back(t);
		}
	}
	
	for(int i = 0; i < n; i++) {
		int qtX = 0, qtY = 0;
		
		mx.clear(); my.clear();
		tempX.clear(); tempY.clear();
		
		for(int j = 0; j < v[i].size(); j++) {
			if(mx.find(v[i][j].x) == mx.end()) {
				qtX++;
				mx.insert(v[i][j].x);
			}
			if(my.find(v[i][j].y) == my.end()) {
				qtY++;
				my.insert(v[i][j].y);
			}
		}
		
		int mxs = mx.size(), mys = my.size();
		//printf("%d %d sizes\n", mxs, mys);
		for(int i = 0; i < mxs; i++) {
			int t = *mx.begin(); mx.erase(mx.begin());
			//printf("t = %d\n", t);
			tempX.push_back(t);
		}
		for(int i = 0; i < mys; i++) {
			int t = *my.begin(); my.erase(my.begin());
			//printf("t = %d\n", t);
			tempY.push_back(t);
		}
		
		int sizeX = tempX.size(), sizeY = tempY.size();
		//printf("SX = %d, SY = %d\n", sizeX, sizeY);
		struct point aux1, aux2;
		if(qtX % 2 == 1) {
			aux1.x = aux2.x = tempX[sizeX/2];
		//	debug("CASE 1: blx = trx = %d = %d\n", aux1.x, aux2.x);
		}
		if(qtY % 2 == 1) {
			aux1.y = aux2.y = tempY[sizeY/2];
		//	debug("CASE 2: bly = try = %d = %d\n", aux1.y, aux2.y);
		}
		if(qtX % 2 == 0) {
			aux1.x = tempX[(sizeX-1)/2];
			aux2.x = tempX[sizeX/2];
		//	debug("CASE 3: blx = %d != trx = %d, sizex/2 = %d, sizex/2 + 1 %d\n", aux1.x, aux2.x, sizeX/2, (sizeX/2)-1);
		}
		if(qtY % 2 == 0) {
			aux1.y = tempY[(sizeY-1)/2];
			aux2.y = tempY[sizeY/2];
		//	debug("CASE 4: bly = %d != try = %d\n", aux1.y, aux2.y);
		}
		
//		debug("RECTANGLE NOW IS %d %d %d %d\n", aux1.x, aux1.y, aux2.x, aux2.y);
		
		in.push_back(pointEvent(aux1, 1));
		in.push_back(pointEvent(aux2, -1));
	}
	
//	for(int i = 0; i < in.size(); i++) {
//		printf("in[%d] = (%d, %d)\n", i, in[i].p.x, in[i].p.y);
//	}
	
	int lastXIn = -1, firstXOut = -1;
	sort(in.begin(), in.end(), sortByX);
	
	for(int i = 0; i < in.size(); i++) {
		if(firstXOut == -1 && in[i].op == -1) {
			firstXOut = in[i].p.x;
			break;
		}
	}

	for(int i = in.size()-1; i >= 0; i--) {
		if(lastXIn == -1 && in[i].op == 1) {
			lastXIn = in[i].p.x;
			break;
		}
	}
	
	int lastYIn = -1, firstYOut = -1;
	sort(in.begin(), in.end(), sortByY);
	
	for(int i = 0; i < in.size(); i++) {
		if(firstYOut == -1 && in[i].op == -1) {
			firstYOut = in[i].p.y;
			break;
		}
	}

	for(int i = in.size()-1; i >= 0; i--) {
		if(lastYIn == -1 && in[i].op == 1) {
			lastYIn = in[i].p.y;
			break;
		}
	}
	
	//printf("%d %d %d %d\n", firstXOut, lastXIn, firstYOut, lastXIn);
	
	long long int ans = (long long int)(lastYIn - firstYOut) * (lastXIn - firstXOut);
	
	printf("%lld\n", (ans < 0) ? -ans : ans);
}
