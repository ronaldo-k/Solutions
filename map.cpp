#include <stdio.h>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

const int MAXN = 1e6 + 10;
const int INF = 2e9;

int n, d, resp, tam, bit[MAXN];
bool dir[MAXN], esq[MAXN];
vector < int > ys;
vector < pair < int, int > > in;
map < int, int > coord;

//\//\/\\\///////\\/\//\//\///\\//\/\\//\/\\\\//\/\/////\\///\\\\\\///\//\////\\

void update(int v, int val) {
    while(v <= tam) {
        bit[v] += val;
        v += v & -v;
    }
}

int query(int v) {
    int resp = 0;
    while(v > 0) {
        resp += bit[v];
        v -= v & -v;
    }
    return resp;
}

//////\/\\\/\//\\/\////\//\/\\/\/\\/\\//\\/\///\/\\//\\////\\\\\\\//\//\\///\\/\

int main() {
    scanf("%d %d", &n, &d);
    
    for(int i = 1; i <= n; i++) {
        int ta, tb;
        scanf("%d %d", &ta, &tb);
        
        in.push_back( make_pair(ta, tb) );
        ys.push_back(tb);
    }
    
    sort(in.begin(), in.end());
    sort(ys.begin(), ys.end());
    
    tam = 0;
    for(int i = 0; i < ys.size(); i++) {
        if(i > 0 && ys[i] == ys[i - 1]) continue;
        tam++;
        coord[ys[i]] = tam;
    }
    
    for(int i = 0; i < in.size(); i++) {
        in[i].second = coord[in[i].second];
    }
    coord.clear();
    
    vector < int > aux;
    //line sweep direita
    dir[0] = false;
    aux.push_back(in[0].second);
    for(int i = 1; i < in.size(); i++) {
        //fprintf(stderr,"ls --> :");
        if(in[i].first != in[i - 1].first) {
            //printf("in[%d].first != in[%d].first = %d\n", i, i-1, in[i-1].first);
            //fprintf(stderr,"in[%d] = %d = in[i - 1] = %d\n", i, in[i].first, in[i - 1].first);
            for(int j = 0; j < aux.size(); j++) {
                update(aux[j], 1);
                //printf(" -> UPDATE: aux[j = %d] = %d", j, aux[j]);
            }
            aux.clear();
        }
        
        //fprintf(stderr,"in[%d].second = %d\n", i, in[i].second);
        
        
        aux.push_back(in[i].second);
        int s1 = query(in[i].second - 1);
        int s2 = query(tam) - query(in[i].second);
        //printf("\nLS -->: i = %d | s1 = %d | s2 = %d\n", i, s1, s2);
        
        dir[i] = !(s1 == 0 || s2 == 0);
    }
    for(int j = 0; j < aux.size(); j++) update(aux[j], 1);
    aux.clear();
    
    for(int i = 1; i <= tam; i++) {
        bit[i] = 0;
    }
        
    //line sweep esquerda
    esq[in.size() - 1] = false;
    aux.push_back(in[in.size() - 1].second);
    for(int i = in.size() - 2; i >= 0; i--) {
        if(in[i].first != in[i + 1].first) {
            for(int j = 0; j < aux.size(); j++) { update(aux[j], 1); }
            aux.clear();
        }
        
        aux.push_back(in[i].second);
        int s1 = query(in[i].second - 1);
        int s2 = query(tam) - query(in[i].second);
        esq[i] = !(s1 == 0 || s2 == 0);
    }
    
    for(int i = 0; i < in.size(); i++) {
        if(dir[i] && esq[i]) resp++;
    }
    
    printf("%d\n",resp);
}