#include<stdio.h>
#include<conio.h>
#define max 100
int edge[max][max];
int trace[max];
int numV, finish, start;

void loadData(){
    int m;
    FILE* fp;
    if((fp=fopen("input.inp","r"))==NULL){
        printf("No such file\n");
        fclose(fp);
        return;
    }
    fscanf(fp, "%d %d %d %d", &numV, &m, &start, &finish);
    int firstE, lastE;
    for(int i=0;i<m;i++){
        fscanf(fp, "%d %d", &firstE, &lastE);
        edge[firstE][lastE]=1;
        edge[lastE][firstE]=1;
    }
    fclose(fp);
}

void DFS(int u)
{
    int v;
    if (u == finish)
        return;
    for (int v = 1; v <= numV; v++)
    {
        if (edge[u][v] == 1 && trace[v] == 0)
        {
            trace[v] = u;
            DFS(v);
        }
    }
}

int main(){
    loadData();
    DFS(start);
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