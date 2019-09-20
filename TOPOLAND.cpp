#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 10;
const int INF = 2e9;

int casos, n, m, balao;
int seg[4*MAXN];

int query(int pos, int ini, int fim, int p, int q) {
    if(p > fim || q < ini) return -INF;
    
    if(p <= ini && fim <= q) return seg[pos];
    
    int m = (ini + fim) /2;
    int e = 2 * pos, d = e + 1;
    
    return max(query(e, ini, m, p, q), query(d, m+1, fim, p, q));
}

void update(int pos, int ini, int fim, int id, int val) {
    if(id > fim || id < ini) return;
    
    if(ini == fim) {
        seg[pos] = val;
        return;
    }
    
    int m = (ini + fim) /2;
    int e = 2 * pos, d = e + 1;
    
    update(e, ini, m, id, val);
    update(d, m+1, fim, id, val);
    
    seg[pos] = max(seg[e], seg[d]);
}

int main() {
    scanf("%d", &casos);
    for(int teste = 1; teste <= casos; teste++) {
        printf("Testcase %d: ",teste - 1);
        scanf("%d", &n);
        
        for(int i = 0; i < n; i++) {
            int ta;
            scanf("%d", &ta);
            update(1, 1, n, i, ta);
        }
        
        scanf("%d",&m);
        for(int i = 1; i <= m; i++) {
            int ta, tb;
            char top;
            
            scanf(" %c", &top);
            
            if(top == 'A') {
                scanf("%d", &ta);
                balao += ta;
            }
            if(top == 'B') {
                scanf("%d %d", &ta, &tb);
                
                update(1, 1, n, ta, tb);
            }
            if(top == 'C') {
                scanf("%d %d", &ta, &tb);
                
                printf("%d\n", balao - query(1, 1, n, ta, tb));
            }
        }
    } 
}