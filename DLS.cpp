#include<stdio.h>
#include<conio.h>
#define max 100
int edge[max][max];
int trace[max];
int numV, finish, start, limit;
int limits[max];

void loadData(){
    int m;
    FILE* fp;
    if((fp=fopen("dls.inp","r"))==NULL){
        printf("No such file\n");
        fclose(fp);
        return;
    }
    fscanf(fp, "%d %d %d %d %d", &numV, &m, &limit, &start, &finish);
    int firstE, lastE;
    for(int i=0;i<m;i++){
        fscanf(fp, "%d %d", &firstE, &lastE);
        edge[firstE][lastE]=1;
        edge[lastE][firstE]=1;
    }
    fclose(fp);
}

void DLS(int u){
    int v;
    if(u==finish)
        return;
    if(limits[u]==limit)
        return;
    for(v=1;v<=numV;v++){
        if(edge[u][v]==1 && trace[v]==0){
            limits[v]=limits[u]+1;
            trace[v]=u;
            DLS(v);
        }
    }
}

int main(){
    loadData();
    limits[start]=0;
    DLS(start);
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