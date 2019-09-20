#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1e5;
const int MAXC = 1e6;
const int INF = 2e9;

struct event {
    int x1, y1, x2, y2, p;
};
struct node {
    int nMax, qtMax, lzSum;
};

vector < struct event > evs;
struct node seg[4 * MAXN];

//////////\\//\/\/\\//\/\/\\/\\//\/\/\\\//\\\/\\\\/\/\\//\\//\\\\/\\\\/\\\\//\//

bool comp(struct event a, struct event b) {
    return a.x1 < b.x1;
};

////\/\\\///\\/\//\\/\\\\\\\\\\/\\\/////\\\/\\////\/\///\\//\///\\\/\\////\\\/\/

void build(int pos, int ini, int fim) {
    seg[pos].nMAX = seg[pos].lzSum = 0;
    seg[pos].qtMax = fim - ini + 1;
    
    int m = (ini + fim) / 2;
    int e = 2 * pos, d = e + 1;
    
    build(e, ini, m);
    build(d, m+1, fim);
}

void refresh(int pos, int ini, int fim) {
    if(seg[pos].lzSum == 0) return;
    
    int k = fim - ini + 1;
    
    seg[pos].nMax += seg[pos].lzSum;
    
    seg[e].lzSum = seg[d].lzSum = seg[pos].lzSum;
    
    seg[pos].lzSum = 0;
}

//\//\/\/\\\/\\//\\/\\//\\\/\///\\\\/\\\\//\////\\\\\\\////\//\///\\\\///\\\//\/

void update(int pos, int ini, int fim, int p, int q, int val) {
    refresh(pos, ini, fim);
    
    if(p > fim || q < ini) return;
    if(p <= ini && fim <= q) {
        seg[pos].lz = val;
        refresh(pos, ini, fim);
        return;
    }
    
    int m = (ini + fim) / 2;
    int e = 2 * pos, d = e + 1;
    
    update(e, ini, m, p, q, val);
    update(d, m+1, fim, p, q, val);
    
    seg[pos].nMax = max(seg[e].nMax, seg[d].nMax);
    
    if(seg[e].nMax == seg[d].nMax) {
        seg[pos].qtMax = seg[e].qtMax + seg[d].qtMax;
    }
    if(seg[e].nMax > seg[d].nMax) {
        seg[pos].qtMax = seg[e].qtMax;
    }
    else {
        seg[pos].qtMax = seg[d].qtMax;
    }
}

//////\\/\/\/\\\\/\\//\/\\//\/\////\\\//\/\\/\\\//\/\\\\//\/\\///\///\//\\//\/\\

int main() {
    int casos;
    scanf("%d", &casos);
    
    for(int teste = 0; teste < casos; teste++) {
        int n;
        scanf("%d", &n);
        
        for(int i = 0; i < n; i++) {
            int tx1, tx2, ty1, ty2;
            struct event aux;
            
            scanf("%d %d %d %d", &tx1, &ty1, &tx2, &ty2);
            
            aux.x1 = tx1; aux.y1 = ty1; aux.x2 = tx2; aux.y2 = ty2;
            
            evs.push_back(aux);
        }
        
        sort(evs.begin(), evs.end(), comp);
        
        int maxAt, aMax;
        
        build(1, 1, MAXC);
        
        for(int i = 1; i < evs.size(); i++) {
            struct event aux = evs[i];
            if(aux.x1 == evs[i-1].x2) {
                continue;
            }
            
            update(1, 1, MAXC, aux.y1, aux.y2, val);
            refresh(1, 1, MAXC);
            
            
        }
    }
}