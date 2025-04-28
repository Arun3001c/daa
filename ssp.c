#include <stdio.h>
#include <limits.h>
struct Edge{
    int src, dest, weight;
};
void printSol(int dist[], int v){
    for(int i=0; i<v; i++){
        if(dist[i]==INT_MAX)
            printf("%d\t\tINF\n", i+1);
        else{
            printf("%d\t\t%d\n", i+1, dist[i]);
        }
    }
}
void ssp(int v, int e, struct Edge ed[], int sou){
    int dist[v];
    for(int i=0; i<v; i++)
        dist[i] = INT_MAX;
    dist[sou] = 0;
    for(int i=1; i<=v-1; i++){
        for(int j=0; j<e; j++){
            int u = ed[j].src;
            int v = ed[j].dest;
            int we = ed[j].weight;
            if(dist[u]+we <dist[v] && dist[u]!=INT_MAX)
                dist[v] = dist[u]+we;
        }
    }
    for(int j=0; j<e; j++){
            int u = ed[j].src;
            int v = ed[j].dest;
            int we = ed[j].weight;
            if(dist[u]+we <dist[v] && dist[u]!=INT_MAX){
                printf("Negative cycle");
                return;
            }
        }
        printSol(dist, v);
}
void main() {
    int v, e, source;
    printf("Enter no of vertices: ");
    scanf("%d", &v);
    printf("Enter no of edges: ");
    scanf("%d", &e);
    struct Edge ed[e];
    printf("Enter edge details: \n");
    for(int i=0; i<e; i++){
        int s, d, w;
        printf("edge %d: ", i+1);
        scanf("%d%d%d", &s, &d, &w);
        ed[i].src = s-1;
        ed[i].dest = d-1;
        ed[i].weight = w;
    }
    printf("Enter src: ");
    scanf("%d", &source);
    source--;
    printf("Single Source Shortest path\n");
    ssp(v, e, ed, source);
}
