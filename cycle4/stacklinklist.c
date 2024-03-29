//IMPLEMENTATION OF STACK USING LINKED LIST
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*link;

}  *top =NULL;

int isEmpty()
{
    if(top==NULL)
    return 1;
    else 
    return 0;
}

void push(int data){
    struct node* newNode;
    newNode =malloc(sizeof( struct newNode));
    if(newNode == NULL)
    {
        printf("Stack overflow");
       exit (1);

    }
    newNode->data=data;
    newNode->link=NULL;

    newNode->link = top;
    top = newNode;
}

int pop(){
    struct node* temp;
   
    if(isEmpty())
    {
        printf("Stack underflow");
       exit (1);
    }
     temp= top;
    int val= temp->data;

    top=top->link;
    free(temp);
    temp= NULL;
    return val;
}
void display()
{
    struct node* temp;
    temp=top;
    
    if(isEmpty())
    {
        printf("Stack underflow");
        exit (1);
    }
    printf("The stack elements are: ");
    while(temp){
        printf("%d", temp->data);
        temp=temp->link;

    }
    printf("\n");
}
int peek()
{
    if(isEmpty())
    {
        printf("Stack Underflow ");
        exit (1);
    }
    return top->data;
    }
    int main()
    {
        int choice, data;
        while(1)
        {
            printf("\n");
            printf("1. Push\n");
            printf("2. Pop\n");
            printf("3. Print the top elements\n");
            printf("4. Print all the elements of the stack\n");
            printf("5. Quit\n");
            printf("Please enter your choice\n");
            scanf("%d",&choice);
        

        switch(choice)
        {
            case 1:
            printf("Enter the element to be pushed ");
            scanf("%d",&data);
            push(data);
            break;

            case 2:
            data = pop();
            printf("Deleted element is  %d", data);
            break;

            case 3:
            printf("The topmost element of the stack is %d\n", peek());
            break;

            case 4:
            display();
            break;

            case 5:
           exit (1);

            default:
            printf("wrong choice");


        }
        }
        return 0;
    }
