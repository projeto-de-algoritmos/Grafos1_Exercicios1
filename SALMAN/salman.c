// Funcionando, mas TLE
#include <stdio.h>
#include <stdlib.h>

long long int soma = 0; //soma op1
long long int min = 0;  //valor minimo da op2

typedef struct Item{
    long long int id;
    long long int sal;
    struct Item *prox;
} Item;

Item *insereNo(Item *cabeca, int id, int sal){
    Item *new = malloc(sizeof(Item));
    new->prox = cabeca->prox;
    new->id = id;
    new->sal = sal;
    cabeca->prox = new;
    return new;
}

long long int op1(Item lider, Item *boss, int *vis){ //DFS para achar a soma
    if(vis[lider.id-1]==1) return soma;
    vis[lider.id-1]==1;
    soma = soma + lider.sal;
    while(lider.prox!=NULL){
        op1(boss[lider.prox->id-1], boss, vis);
        lider.prox = lider.prox->prox;
    }
    return soma;
}

Item *op2(Item lider, Item *boss, int *vis){ //DFS para achar o min
    if(vis[lider.id-1]==1) return boss;
    vis[lider.id-1]==1;
    if(min>lider.sal) min=(lider.sal<1000 ? lider.sal : 1000);
    while(lider.prox!=NULL){
        op2(boss[lider.prox->id-1], boss, vis);
        lider.prox = lider.prox->prox;
    }
    boss[lider.id-1].sal += min;
    return boss;
}

int main(){
    long long int t, nodes, queries, op, id, p, s;
    scanf("%lld", &t);
    char buffer;
    for(int j=0; j<t; ++j){
        scanf("%c", &buffer);
        printf("Case %d:\n", j+1);
        scanf(" %lld %lld", &nodes, &queries);
        Item *boss = malloc(100001*sizeof(Item));
        for(int i=0; i<nodes; ++i){
            scanf(" %lld %lld", &p, &s);
            if(p==0){
                boss[p].id = 1;
                boss[p].sal = s;
            } else {
                boss[i].id = i+1;
                boss[i].sal = s;
                insereNo(&boss[p-1], boss[i].id, boss[i].sal);
            }
        }
        for(int k=0; k<queries; ++k){
            long long int retorno = 0;
            int *visitados = malloc(sizeof(int)*100001);
            scanf(" %lld %lld", &op, &id);
            if(op==1){
                soma = 0;
                retorno = op1(boss[id-1], boss, visitados);
                printf("%lld\n", retorno);
            }
            else {
                min = boss[id-1].sal;
                op2(boss[id-1], boss, visitados);
            }
            free(visitados);
        }
        free(boss);
    }
    return 0;
}
