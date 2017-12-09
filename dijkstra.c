#include<stdio.h>
#include<stdlib.h>
#define inf 2100000000 
int main(){
    int a[10][10]={0};
    int dist[10]={0};
    int path[10][100]={0};
    int vis[10]={0};
    FILE *fin;
    fin=fopen("input.txt","r");
    int n,m,i,j;
    int u,v,w;
    int t,min=inf;
    
    fscanf(fin,"%d%d",&n,&m);
    for(i=1;i<=m;i++){
      fscanf(fin,"%d%d%d",&u,&v,&w);
      a[u][v]=w;
    }
    
    
    /////////  main function  ////////
    
    for(i=2;i<=n;i++)
      if(a[1][i]!=0){
        dist[i]=a[1][i];
      }
      else  dist[i]=inf;
    
    
    for(i=1;i<=n-1;i++){
      min=inf;
      for(j=2;j<=n;j++)
        if(dist[j]<min&&vis[j]==0){
          min=dist[j];
          t=j;
        }printf("%d\n",t);
      vis[t]=1;
      for(j=1;j<=n;j++)
        if(a[t][j]!=0&&a[t][j]+dist[t]<dist[j]&&vis[j]==0){
          dist[j]=a[t][j]+dist[t];
          
        }
    }
    
    ///////////////////////////////////
    
    
    
    for(j=1;j<=n;j++)
      printf("%d ",dist[j]);
    system("pause");
    return 0;
}
