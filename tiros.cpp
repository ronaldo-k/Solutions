#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

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
    
    long long int cross(struct point a) const {
        return (x * a.y) - (y * a.x); 
    }
    
    long long int dot(struct point a) const {
        return (x * a.x) + (y * a.y);
    }
    
    bool operator<(struct point a) const {
        if(quadrante() != a.quadrante()) {
            return quadrante() < a.quadrante();
        }
        
        if(cross(a) == 0LL) {
            return dot(*this) < a.dot(a);
        }
        
        return cross(a) > 0LL;
    }
};

vector < struct point > in;
vector < struct point > aux;

int main() {
    int casos;
    scanf("%d", &casos);
    
    for(int teste = 0; teste < casos; teste++) {
        in.clear();
        
        int n;
        scanf("%d", &n);
        
        for(int i = 0; i < n; i++) {
            struct point aux;
            
            scanf("%lld %lld", &aux.x, &aux.y);
            
            in.push_back(aux);
        }
        
        int at, maxCol; // qtd atual de pontos colineares e qtd maxima de pontos colineares
        at = maxCol = 2;
        
        for(int i = 0; i < n; i++) {
            at = 2;
            aux.clear();
            
            int orig = i;
            
            for(int j = 0; j < n; j++) {
                //fprintf(stderr, "1. j = %d\n", j);
                if(j != orig) {
                    aux.push_back(in[j] - in[orig]);
                }
            }
            
            sort(aux.begin(),aux.end());
            
            for(int j = 1; j < aux.size(); j++) {
                //fprintf(stderr, "2. j = %d\n", j);
                if( aux[j].cross(aux[j - 1]) == 0LL ) { // Se sao colineares
                    at++;
                }
                else {
                    at = 2;
                }
                
                maxCol = max(at, maxCol);
            }
        }
        
        printf("%d\n",maxCol);
    }
}