#include <stdio.h>
#include <vector>
using namespace std;

int n, m;
bool ok;

struct point {
    long long int x, y;
    
    struct point operator-(struct point a) {
        struct point aux;
        aux.x = x - a.x;
        aux.y = y - a.y;
        return aux;
    }
    
    int quadrante() const {
        if(x >= 0LL && y >= 0LL) return 1;
        if(x < 0LL  && y > 0LL ) return 2;
        if(x <= 0LL && y <= 0LL) return 3;
        if(x > 0LL  && y < 0LL ) return 4;
    }
    
    long long int cross(struct point a) {
        return (x * a.y) - (y * a.x);
    }
    
    long long int dot(struct point a) {
        return (x * a.x) + (y * a.y);
    }
    
    bool operator<(struct point a) {
        if(quadrante() != a.quadrante()) {
            return quadrante() < a.quadrante();
        }
        
        if(cross(a) == 0LL) {
            return dot(*this) < a.dot(a);
        }
        
        return cross(a) > 0LL;
    }
};

vector < struct point > inA, inB;

//\////////\/\\//\\//\\\\////\/\/\\/\\\\//\\\/\\//\\\/////\\\//\\//\/\\\/\\/\\\/

void binarySearch(int cur) {
    int ini = 1, fim = n - 1;
    if( (inA[fim]-inA[0]).cross(inB[cur]-inA[0]) <= 0 ) {
    //if( in[fim].cross(in[0]) - in[cur].cross(in[0]) <= 0) {
        ok = false;
        return;
    }
    
    while (ini < fim) {
        int mid = (ini + fim) / 2;
        if( (inA[mid] - inA[0]).cross(inB[cur] - inA[0]) >= 0 ) {
            fim = mid;
        }
        else ini = mid + 1;
    }
    
    if(fim == 1) ok = false;
    else if ( (inA[fim - 1] - inA[fim]).cross(inB[cur] - inA[fim]) <= 0) ok = false;
    else ok = true;
}

////\\///\/\/\//\/\\/\\\\/\\\\/\//\\/\\\//////\/\/\\\/////\//\\//\//\\//\/\///\/

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        struct point aux;
        scanf("%lld %lld", &aux.x, &aux.y);
        inA.push_back(aux);
    }
    
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        struct point aux;
        scanf("%lld %lld", &aux.x, &aux.y);
        inB.push_back(aux);
    }
    
    for(int i = 0; i < m; i++) {
        binarySearch(i);
        
        if(!ok) break;
    }
    
    if(ok) printf("YES\n");
    else printf("NO\n");
}