#include <stdio.h>
#include <stdlib.h>

int tamanho = 0;
int last = 0;

typedef struct Item{
    int dado;
    struct Item *prox;
} Item;

int visitados[10000];

Item *insereNo(Item *cabeca, int dado){
    Item *new = malloc(sizeof(Item));
    new->prox = cabeca->prox;
    new->dado = dado;
    cabeca->prox = new;
    return new;
}

void zeraVisita(){
    for(int i=0; i<10001; ++i) visitados[i] = 0;
}
void DFS(Item node, Item *lista, int max){
    if(visitados[node.dado]==1) return;
    visitados[node.dado]=1;
    while(node.prox!=NULL){
        DFS(lista[node.prox->dado], lista, max+1);
        node.prox = node.prox->prox;
    }
    if(tamanho<max){
        tamanho = max;
        last = node.dado;
    }
}

int main(){
    int N, u, v, max = 0;
    scanf(" %d", &N);
    Item *nodes = (Item*)malloc(sizeof(Item)*10000);
    for(int i=0; i<(N-1); ++i){
        scanf(" %d %d", &u, &v);
        nodes[u].dado = u;
        nodes[v].dado = v;
        insereNo(&nodes[u], v);
        insereNo(&nodes[v], u);
    }
    DFS(nodes[v], nodes, 0);
    zeraVisita();
    DFS(nodes[last], nodes, 0);
    printf("%d\n", tamanho);
    return 0;
}
