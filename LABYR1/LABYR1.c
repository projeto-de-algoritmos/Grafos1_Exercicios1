#include <stdio.h>
#include <stdlib.h>

char matriz[1005][1005];
int tamanho = 0;
int visited[1005][1005];
int coluna, linha;
int sinkx=0, sinky=0;

void zeravisita() {
    for(int i=0;i<1001;++i)
        for(int j=0;j<1001;++j)
            visited[i][j] = 0;
}

void DFS(int q, int w, int max){
    visited[q][w]=1;
    int count = 0;
    if(matriz[q][w]=='.' && q<linha && w<coluna && q>-1 && w>-1){
        if(matriz[q+1][w]=='.' && q<(linha-1) && visited[q+1][w]==0){
            count++;
            DFS(q+1, w, max+1);
        }
        if(matriz[q-1][w]=='.' && q>0 && visited[q-1][w]==0){
            count++;
            DFS(q-1, w, max+1);
        }
        if(matriz[q][w+1]=='.' && w<(coluna-1) && visited[q][w+1]==0){
            count++;
            DFS(q, w+1, max+1);
        }
        if(matriz[q][w-1]=='.' && w>0 && visited[q][w-1]==0){
            count++;
            DFS(q, w-1, max+1);
        }
        if(count!=0) max++;
    } else return;
    if(max>tamanho){
        tamanho = max;
        sinkx = q;
        sinky = w;
    }
}

int main(){
    int t;
    int inix, iniy;
    scanf(" %d", &t);
    for(int i=0; i<t; ++i){
        sinkx = 0;
        sinky = 0;
        tamanho = 0;
        scanf(" %d %d", &coluna, &linha);
        for(int j=0; j<linha; ++j){
            for(int k=0; k<coluna; ++k){
                scanf(" %c", &matriz[j][k]);
                if(matriz[j][k]=='.'){
                    inix = j;
                    iniy = k;
                }
            }
        }
        DFS(inix, iniy, 0);
        zeravisita();
        DFS(sinkx, sinky, 0);
        zeravisita();
        printf("Maximum rope length is %d.\n", tamanho);
    }
    return 0;
}