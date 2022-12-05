//not correct
#include<stdio.h>
struct node{
int data;
struct node*link;
};
struct node *front=NULL, node *rear=NULL;

void Enqueue()
{struct node*newnode;
newnode=newnode malloc(sizeof(newnode));
newnode->data= item;
newnode->link=NULL;

if(front==NULL)
{
front=rear=newnode;
}
else
{
rear->next=newnode;
rear=newnode;
}
}

void Dequeue()
{
if(front==NULL)
printf("the queue is empty");
 
else if(front==rear)
temp=front;
front=rear=NULL;
free(temp);
}

void display()
{
if(front==NULL)
printf("the queue is empty");
else
struct node*ptr;
ptr=front;
while(ptr!=NULL)
printf("%d",ptr->data)
ptr= ptr->next;

int main(){
int choice;int element;
while(1)
{       printf("\n\nChoose operation");
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Display queue");
        printf("\n4.Display Front Element");
        printf("\n5.Exit\n");
        scanf("%d", &ch);
        switch(ch){
        
        case 1:
        printf("Enter the element");
        scanf("%d",&element);
        enqueue(element);
        break;
        
        case2:
        dequeue;
        break;
        
        case3:
        display();
        break;
        
        case4:
       
	        if(front == -1)
	        {
	        	printf("Queue Empty!");
	        }
	        else
	        {
                printf("Front element: %d", peek());
	        }
            break;
        
        default:
        printf("you have entered the wrong option");
        }
