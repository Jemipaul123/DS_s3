#include <stdio.h>

#define MAX 5


int queue[MAX], front = -1, rear = -1;


void enqueue(int data)
{
    if (rear == MAX - 1)
        printf("\n Queue overflow");
    else if(rear == -1)
    {
    	front = 0;
    	rear  = 0;
    	queue[rear] = data;
    }
    else
		queue[++rear] = data;
}


void dequeue()
{
    int del;
    if (front == -1)
        printf("\nQueue empty");
    else if(front == rear)
    {
    	printf("\nDeleted: %d", queue[front]);
    	front = -1;
    	rear  = -1;
    }
    else
    {
        del = queue[front++];
        printf("\nDeleted: %d", del);
    }
}



int peek()
{
	if(front == -1)
		return -1;
	else
		return queue[front];
}



void display()
{
    if (front== -1)
        printf("\nQueue empty");
    else
    {
        printf("\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d, ", queue[i]);
        }
    }
}

int main()
{
    int ch, element;
    do
    {
        printf("\n\nChoose operation");
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Display queue");
        printf("\n4.Display Front");
        printf("\n5.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter element to insert ");
            scanf("%d", &element);
            enqueue(element);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
	        if(front == -1)
	        {
	        	printf("Queue Empty!");
	        }
	        else
	        {
                printf("Front element: %d", peek());
	        }
            break;
        }
    } while (ch < 5);

    return 0;
}
