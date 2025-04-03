#include <stdio.h>

#define NODE_COUNT 8
#define QUEUE 100

int graph[NODE_COUNT ][NODE_COUNT ] = {
    {2, 3, 4},   // Node 1
    {1, 5, 6},   // Node 2
    {1},         // Node 3
    {1, 7},      // Node 4
    {2, 8},      // Node 5
    {2, 8},      // Node 6
    {4},         // Node 7
    {5, 6}       // Node 8
};

int visited[NODE_COUNT] = {0};
void dfs(int node){
    int neighbor = 0;
    printf("%d\n",node);
    visited[node] = 1;
    for (int i = 0;i < sizeof(graph[node])/sizeof(graph[node][0]);i++){
        neighbor = graph[node][i];
        if(!visited[neighbor]){
            dfs(neighbor);
        }
    }
}

void main(){
    visited[0] = 1;
    dfs(0);
}