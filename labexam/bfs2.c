#include<stdio.h>

int queue[100];int graph[100][100];
int front=0,back=0;

void push(int var)
{
    queue[back] = var;
    back++;
}
void pop()
{
    queue[front] = 0;
    front++;
}
int visited[7] = {0};

int main()
{
    int n;
   printf("enter the size ");
   scanf("%d",&n);
   printf("enter the elements");
   {for(int i=0;i<n;i++)
   {
    for(int j=0;j<n;j++)
    {
        scanf("%d",&graph[i][j]);
    }} }
    push(1);
    visited[0] = 1; // marking 1st node as visited 
    while(front != back)
    {
        int current = queue[front];
        printf("%d ", current);
        
        // popping the front element from the queue
        pop();
 
        for(int i=0;i<n;i++)
        {
            // adding non-visited connected nodes of the current node to the queue 
            if((graph[current-1][i] == 1) && (visited[i] == 0))
            {
                visited[i] = 1; // marking visisted
                push(i+1);
            }
        }
    }
    return 0;
}
