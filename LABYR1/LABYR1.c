#include <stdio.h>
#include <stdlib.h>

char matriz[1005][1005];
int tamanho = 0;
int visited[1005][1005];
int coluna, linha;
int sinkx=0, sinky=0;

void DFS(int q, int w, int max, int p){
    visited[q][w]++;
    int count = 0;
    if(matriz[q][w]=='.' && q<linha && w<coluna && q>-1 && w>-1){
        if(matriz[q+1][w]=='.' && visited[q+1][w]==p){
            count++;
            DFS(q+1, w, max+1, p);
        }
        if(matriz[q-1][w]=='.' && visited[q-1][w]==p){
            count++;
            DFS(q-1, w, max+1, p);
        }
        if(matriz[q][w+1]=='.' && visited[q][w+1]==p){
            count++;
            DFS(q, w+1, max+1, p);
        }
        if(matriz[q][w-1]=='.' && visited[q][w-1]==p){
            count++;
            DFS(q, w-1, max+1, p);
        }
        if(count!=0) max++;
    }
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
                    visited[j][k] = 0;
                }
            }
        }
        DFS(inix, iniy, 0, 0);
        DFS(sinkx, sinky, 0, 1);
        printf("Maximum rope length is %d.\n", tamanho);
    }
    return 0;
}