#include <stdio.h>

#define ROW 9
#define COL 9
#define QUEUE 100

int graph[ROW][COL] = {0};
int visited[ROW][COL] = {0};
int front = -1;
int rear = -1;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int pathlen = 0;

typedef struct{
    int x,y;
} point;

point queue[QUEUE];
point path[ROW*COL];

void enqueue(point data){
    if ((rear + 1) % QUEUE == front){
        printf("Overflow\n");
        return;
    }
    if (front == -1){
        front = 0;
    }
    rear = (rear+1) % QUEUE;
    queue[rear] = data;
}

point dequeue(){
    point data;
    if (front == -1){
        printf("Underflow\n");
        data.x = -1;
        data.y = -1;
        return data;
    }
    data = queue[front];
    if (front == rear){
        front = rear = -1;
    }else{
        front = (front + 1) % QUEUE;
    }
    return data;
}

int pathfind(int sx, int sy, int gx, int gy){
    point current = {sx,sy};
    point next;
    int nx,ny;

    for (int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            visited[i][j]= -1;
        }
    }
    visited[sx][sy] = 0;
    enqueue(current);
    while (front != -1){
        current = dequeue();
        if (current.x == gx && current.y == gy){
            return visited[gx][gy];
        }
        for (int i = 0; i < 4;i++){
            next.x = current.x + dx[i];
            next.y = current.y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < ROW && ny < COL && visited[nx][ny] == -1 && graph[nx][ny] == 0){
                visited[nx][ny] = visited[current.x][current.y] + 1;
                enqueue(next);
            }
        }
    }
    return -1;
}

void backtrack(int sx, int sy, int gx, int gy){
    int mindist = 0;
    int nx = 0,ny = 0,tx = 0, ty = 0,cx = 0, cy =0;
    if (visited[gx][gy] == -1){
        printf("No path\n");
        return;
    }
    cx = gx;
    cy = gy;
    path[pathlen++] = (point){cx,cy};
    mindist = visited[cx][cy];
    while (mindist != 0){
        for (int i = 0; i < 4; i++){
            tx = cx + dx[i];
            ty = cy + dy[i];
            if (tx >= 0 && ty >= 0 && tx < ROW && ty < COL && visited[tx][ty] == mindist - 1){
                mindist = visited[tx][ty];
                cx = tx;
                cy = ty;
                break;
            }
        } 
        path[pathlen++] = (point){cx,cy};
    } 
    printf("Path : \n");
    for(int i = pathlen; i > 0;i--){
        printf("%d\t%d\n",path[i-1].x,path[i-1].y);
    }
}

void main(){
    int sx = 2,sy = 3;
    int gx = 6,gy = 7;
    int ispath=0;
    printf("Hello World\n");
    pathfind(sx,sy,gx,gy);
    for (int i = 0; i < ROW;i++){
        for (int j = 0;j<COL;j++){
            printf("%2d",visited[i][j]);
        }
        printf("\n");
    }
    backtrack(sx,sy,gx,gy);
    for (int i = 0; i < ROW;i++){
        for (int j = 0;j<COL;j++){
            ispath = 0;
            for (int k = 0;k < pathlen;k++){
                if (i == path[k].x && j == path[k].y){
                    printf(" *");
                    ispath = 1;
                    break;
                }
            }
            if (ispath){
                continue;
            }
            printf("%2d",visited[i][j]);
        }
        printf("\n");
    }
}