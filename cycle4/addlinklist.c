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
temp->next=newnode;}}
void Atany(int data,int pos){
   struct node* newnode = (struct node*)malloc((sizeof(struct node)));
    newnode->data=data;
    newnode->next=NULL;

if(pos==0)
{
    newnode->next=head;
     head=newnode;
}

else{
struct node* temp=head;
for(int i=1;i<pos;i++)
{
    temp=temp->next;
}
newnode->next=temp->next;
temp->next=newnode;

}}
void Addfirst(int data)
{
   struct node* newnode = (struct node*)malloc((sizeof(struct node)));
    newnode->data=data;
    newnode->next=NULL;

if(head==NULL)
{
    head=newnode;
}
else{
newnode->next=head;
head=newnode;

}}
void display(){
    if(head==NULL)
    printf("The list is empty\n");
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
        int data;int pos;
        printf("1: Add element at end\n");
        printf("2: Add element at first\n");
        printf("3: Add element at any position\n");
        printf("4: Display Elements\n");
        printf("5: Exit\n");
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
                printf("Enter value: ");
                scanf("%d",&data);
                Addfirst(data);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d",&data);
                printf("enter pos");
                scanf("%d",&pos);
                Atany(data,pos);
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
    }while(choice != 5);
    return 0;
}   


