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
int queue[QUEUE];
int front = -1;
int rear = -1;

void enqueue(int data){
    if ((rear + 1) % QUEUE == front){
        printf("Overflow\n");
        return;
    }
    if (front == -1){
        front = 0;
    }
    rear = (rear + 1) % QUEUE;
    queue[rear] = data;
}

int dequeue(){
    if (front == -1){
        printf("Underflow\n");
        return -1;
    }
    int data = queue[front];
    if (front == rear){
        front = rear = -1;
    }
    else{
        front = (front + 1) % QUEUE;
    }
    return data;
}

void bfs(int startNode){
    int node = 0;
    int neighbor = 0;
    enqueue(startNode);
    visited[startNode] = 1;
    printf("%d\n",rear);
    while(!(front == -1)){
        node = dequeue();
        printf("%d\n",node);
        for (int i = 0; i < sizeof(graph[node])/sizeof(graph[node][0]);i++){
            neighbor = graph[node][i];
            if (!visited[neighbor]){
                enqueue(neighbor);
                visited[neighbor] = 1;
            }
        }
    }
}

void main(){
    printf("hello world");
    bfs(0);
}