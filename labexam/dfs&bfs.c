//graph traversal


void dfs(int i){
    int j;
    visited[i]=1;
    printf("%d",i);
    for(j=1;j<=v;j++)
    {
        if(g[i][j]==1 && visited[j]==0)
        dfs(j);
    }
}

void bfs(int s){
    int i;
    visited[s]=1;
    printf("%d", &s);
  enqueue(s);
    while(front!=-1){
        s=dequeue();
        for(i=1;i<=V;i++)
        {
            if g[s][i]==1 && visited[i]==0
            {
                printf("%d",i);
                visited[i]=1;
                enqueue(i);
            }
        }
    }
}

void main(){
    int i,j,v1,v2,opt;
    printf("enter the no: of vertices of the graph");
    scanf("%d",&v);
    for(int i=1;i<=v;i++)
    for(int j=1;j<=v;j++)
    {
        g[i][j]=0;
    }
    printf("enter the number of edges v1 v2");
    scanf("%d",&e);

    for(int i=1;i<=e;i++)
    {
        scanf("%d %d", &v1,&v2);
        g[v1][v2]=1;
        g[v2][v1]=1;
    }
    printf("adjacency matrix");
    {
        for(int i=1;i<=v;i++)
        {
            for(j=1;j<=v;j++)
            {
                printf("%d",g[i][j]);
            }
        }
    }
    for (int i=0;i<=v;i++)
    visited[i]=0;
    printf("source");
    scanf("%d",&source);
     printf("dfs");
    dfs(source);
     printf("bfs");
    bfs(source);

}
