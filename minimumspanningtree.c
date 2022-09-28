#include<stdio.h>
#include<limits.h>
  int n;
int findminnode(int dist[],int visited[]){
       int min=INT_MAX;
       int i;
       int x;
       for(i=0;i<n;i++){
           if(visited[i]==0&&dist[i]<=min){
               min=dist[i];
               x=i;
           }
       }
       return x;
}
int main(){
  
    scanf("%d",&n);
    int a[n][n];
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           scanf("%d",&a[i][j]);
       }
    }
    int dist[n];
    dist[0]=0;
    for(int i=1;i<n;i++){
        dist[i]=INT_MAX-10;
    }
    int visited[n];
     for(int i=0;i<n;i++){
         visited[i]=0;
    }
    int parent[n];
     for(int i=0;i<n;i++){
        parent[i]=-1;
    }
    int i,j;
    for( i=0;i<n;i++){
        int k=findminnode(dist,visited);
        visited[k]=1;
        for(j=0;j<n;j++){
           if(a[k][j]!=-1&&visited[j]!=1){//checking whether the node has connection or not as well as it has visited or not 
              if(dist[j]>a[k][j]){
                  dist[j]=a[k][j];
                  parent[j]=k;
              }
           }
        }    
    }
    int sum=0;
    for(i=0;i<n;i++){
       sum=sum+dist[i];
    }
    for(int i=0;i<n;i++){
         printf("%d\t",dist[i]);
         
    }   
    printf("\n");
    printf("minimum distance :%d",sum);
return 0;
}
