//CREATION OF LINKEDLIST WITH N ELEMENTS
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node*head=NULL;

void Createnode(int data){
   struct node* newnode = (struct node*)malloc((sizeof(struct node)));
    newnode->data=data;
    newnode->next=NULL;

if(head==NULL)
{
    head=newnode;
}
else{
struct node* temp=head;
while(temp->next !=NULL)
{
    temp=temp->next;
}
temp->next=newnode;

}}
void display(){
    if(head==NULL)
    printf("the list is empty");
    else
    {
        struct node*temp=head;
        while(temp!=NULL)
        {
            printf(" %d",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }}
    int main()
{
    int choice;
    do
    {
        int data;
        printf("1: Add elements\n");
        printf("2: Display Elements\n");
        printf("3: Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&data);
                Createnode(data);
                break;
            case 2:
                display();
                break;
        
            case 3:
                break;
            default:
                printf("Invalid Choice\n");
                break;
        };
    }while(choice != 3);
    return 0;
}   
