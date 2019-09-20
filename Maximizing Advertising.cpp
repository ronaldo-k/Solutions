#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int qtdB, qtdW, totB, totW, respX, respY, resp;
// Quantidade parcial dos partidos B e W, resposta das linesweeps em x (Linha vertical) e y (Linha horizontal). ZERAR OS QTDs e RESPs ANTES DE CADA LINESWEEP.

struct event {
    int x, y; // Abcissa e ordenada
    char pt; //partido (b/w)
};

vector < struct event > evsX;
vector < struct event > evsY;

//\/\/////////\\\\/\\\\/////\\\\\\/\/\\/\\//\/\\/\\\//////\//\\\\///\\\/\//\/\\/

bool compX(struct event a, struct event b) {
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

bool compY(struct event a, struct event b) {
    if(a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

/////\//\\/\//\////\\/\/\\///\/\/\\\\/\\/\\\\//\\\\/\\\/\/\/\\\\/\\/\\/\/\\/\//\

int main() {
    int n; // Numero de pontos.
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        int ta, tb;
        char tp;
        struct event aux;
        
        scanf("%d %d %c", &ta, &tb, &tp);
        
        if(tp == 'b') totB++;
        else totW++;
        
        aux.x = ta; aux.y = tb; aux.pt = tp;
        evsX.push_back(aux);
        evsY.push_back(aux);
    }
    
    sort(evsX.begin(), evsX.end(), compX);
    sort(evsY.begin(), evsY.end(), compY);
    
    qtdB = qtdW = 0;
    
    //printf("LINESWEEP EM X: (totB = %d | totW = %d)\n", totB, totW);
    for(int i = 0; i < evsX.size(); i++) { // Linesweep em x (Linha vertical)
        //printf(" -> qtdB = %d | qtdW = %d | respX = %d", qtdB, qtdW, respX);
        
        if(evsX[i].pt == 'b') qtdB++;
        else qtdW++;
        
        respX = max(respX, max(qtdB + (totW - qtdW), qtdW + (totB - qtdB)));
        //printf(" => respX = %d\n", respX);
    }
    
    qtdB = qtdW = 0;
    
    //printf("LINESWEEP EM Y: (totB = %d | totW = %d)\n", totB, totW);
    for(int i = 0; i < evsY.size(); i++) { // Linesweep em y (Linha horizontal)
        //printf(" -> qtdB = %d | qtdW = %d | respY = %d", qtdB, qtdW, respY);
        
        if(evsY[i].pt == 'b') qtdB++;
        else qtdW++;
        
        respY = max(respY, max(qtdB + (totW - qtdW), qtdW + (totB - qtdB)));
        //printf(" => respY = %d\n", respY);
    }
    
    printf("%d\n", max(respX, respY));
}