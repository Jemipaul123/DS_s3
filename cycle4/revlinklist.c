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
void reverse(){
    struct node* temp=NULL;
    struct node* temp2=head->next;
    while(temp2!=NULL)
    {temp2=head->next;
    head->next =temp;
    temp=head;
    head=temp2;}
    head=temp;

}
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
        printf("3: Reverse list\n");
        printf("4. Exit\n");
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
            reverse();
                break;

            case 4:
                break;
            default:
                printf("Invalid Choice\n");
                break;
        };
    }while(choice != 4);
    return 0;
}   
