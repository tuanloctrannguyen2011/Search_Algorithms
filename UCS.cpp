#include<stdio.h>
#include<conio.h>
#define max 100
int edge[max][max];
int trace[max];
int numV, finish, start;
int front=1,rear=1,u,v;

typedef struct Node{
    int vertex;
    int cost;
}Node;
Node queue[max];

void loadData(){
    int m;
    FILE* fp;
    if((fp=fopen("ucs.inp","r"))==NULL){
        printf("No such file\n");
        fclose(fp);
        return;
    }
    fscanf(fp, "%d %d %d %d", &numV, &m, &start, &finish);
    int firstE, lastE, cost;
    for(int i=0;i<m;i++){
        fscanf(fp, "%d %d %d", &firstE, &lastE, &cost);
        edge[firstE][lastE]=cost;
    }
    fclose(fp);
}

void enqueue(int vertex, int value){
    Node v;
    v.vertex=vertex;
    v.cost=value;
    int index;
    for(index=front;index<=rear;index++){
        if(v.cost<queue[index].cost){
            break;
        }
    }
    if(index==rear+1){
        rear++;
        queue[rear]=v;
    }else{
        for(int k=rear;k>=index;k--){
            queue[k+1]=queue[k];
        }
        queue[index]=v;
        rear++;
    }
}

Node dequeue(){
    Node u=queue[front];
    front++;
    return u;
}

int isEmpty(){
    if(front>rear)
        return 1;
    return 0;
}

void UCS(){
    Node nodeStart;
    nodeStart.vertex=start;
    nodeStart.cost=0;
    queue[front]=nodeStart;
    trace[start]=-1;
    do{
        u=dequeue().vertex;
        if(u==finish)
            break;
        for(int v=1; v<=numV;v++){
            if(edge[u][v]!=0 && trace[v]==0){
                enqueue(v,edge[u][v]);
                trace[v]=u;
            }
        }
    }while (!isEmpty());
}

int main(){
    loadData();
    UCS();
    if(trace[finish]==0)
        printf("khong tim thay duong\n");
    else
    {
        while(finish!=start){
            printf("%d <- ",finish);
            finish=trace[finish];
        }   
        printf("%d",start);
    }
    getch();
}