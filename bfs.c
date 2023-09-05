#include<stdio.h>
#include<stdbool.h>
#include<time.h>

int a[10][10],source,n;

void bfs(int a[10][10], int n, int source){
    bool visited[10]={false};
    int queue[10],front=0,rear=0;
    queue[rear++]=source;
    visited[source]=true;
    printf("The bfs traversal is: \n");
    while (front<rear){
        int currentnode=queue[front++];
        for(int i=0;i<n;i++){
            if(a[currentnode][i] && !visited[i]){
                visited[i]=true;
                printf("%d to %d\n",currentnode,i);
                queue[rear++]=i;
            }
        }
    }


}
int main(){
    printf("Enter the length of adjacency matrix: ");

    scanf("%d",&n);
    
    printf (" Enter the adjacency matrix: ");
    for ( int i =0; i<n;i++){
        for (int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the source Vertex: ");
   
    scanf("%d",&source);
    clock_t startime, endtime;
    double clk;
    startime=clock();
    bfs(a,n,source);
    endtime=clock();
    clk= (endtime-startime)/CLOCKS_PER_SEC;
    printf("The runtime for the give bfs traversal is: %f",clk);
}
