#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};

struct node *front =NULL, *rear=NULL;

void enqueue(int data)
{
     struct node* newNode = (struct node*)malloc((sizeof(struct node)));
      newNode->next = NULL;
    newNode->data = data;
    if(rear == NULL)
    {
		front = newNode;
		rear  = newNode;
    }
    else
    {
		rear->next = newNode;
		rear = newNode;
    }
    printf("enqueued: %d\n", data);
}


void pop()
{
    
    if(front == NULL)
    {
        printf("\n Queue Empty\n");
    }
    else
    {
    	printf("dequeued: %d\n", front->data);
    	struct node* temp = front;
    	front = front->next;
    	free(temp);
    	if(front == NULL)
    		rear = NULL;
    }
}
void peek()
{
    if(front == NULL)
        printf("\n Queue Empty");
    else
    {
        printf("\n Front: %d", front->data);
    }
    printf("\n");
}
void display()
{ struct node* temp=front;
    if(front ==NULL)
    {
        printf("queue is empty");
    }
    else{
        while(temp->next !=NULL)
        {printf("%d\t",temp->data);
        temp=temp->next;
    }
}}
int main()
{
    int choice;
    do
    {
        int data;
        printf("1: Enqueue\n");
        printf("2: Peek\n");
        printf("3: Dequeue\n");
        printf("4: Display\n");
        printf("5: Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&data);
                enqueue(data);
                break;
            case 2:
                peek();
                break;
            case 3:
                dequeue();
                break;
            case 4:
            display();
                break;
                case 5:
                break;
            default:
                printf("Invalid Choice\n");
                break;
        };
    }while(choice != 4);
    return 0;
}
