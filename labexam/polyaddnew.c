//polynomial addition

#include<stdio.h>
#include<stdlib.h>


struct node{
    int coeff;
    int expo;
    struct node* next;
};

struct node *phead,*qhead,*rhead;
 struct node *readpoly(){
    int n;
    struct node*head=NULL,*temp;
    printf("enter the total number of terms in the polynomial");
    scanf("%d",&n);
    printf("enter the coefficient and exponents of the polynomial");
    for(int i=0;i<n;i++)
    {struct node* newnode= (struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->coeff);
        scanf("%d",&newnode->expo);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
            temp=head;

        }
        else{
           
            temp->next=newnode;
            temp=newnode;
        }
    }
return(head);
}
struct node *addpoly(){
    struct node *p,*q,*r,*newnode,*head=NULL;
    p=phead;
    q=qhead;
    

    while(p!=NULL && q!=NULL)
    {
        if(p->expo== q->expo){
            struct node* newnode= (struct node*)malloc(sizeof(struct node));
            newnode->coeff= p->coeff + q->coeff;
            newnode->expo=p->expo;
            newnode->next=NULL;
            p=p->next;
            q=q->next;
        }
       else if(p->expo > q->expo){
            struct node* newnode= (struct node*)malloc(sizeof(struct node));
            newnode->coeff= p->coeff; 
            newnode->expo=p->expo;
            newnode->next=NULL;
            p=p->next;
            
        }
        else
        {struct node* newnode= (struct node*)malloc(sizeof(struct node));
            newnode->coeff= q->coeff; 
            newnode->expo=q->expo;
            newnode->next=NULL;
            q=q->next;}
            
    
    if(head==NULL)
    { 
        head=newnode;
        r=head;
    }
    else{
        r->next=newnode;
        r=newnode;
    } }
    while(p!=NULL){
          struct node* newnode= (struct node*)malloc(sizeof(struct node));
            newnode->coeff= p->coeff ;
            newnode->expo=p->expo;
            newnode->next=NULL;
            

 if(head==NULL)
    {
        head=newnode;
        r=head;
    }
    else{
        r->next=newnode;
        r=newnode;
    }
    p=p->next;
    }
    while(q!=NULL){
        struct node* newnode= (struct node*)malloc(sizeof(struct node));
            newnode->coeff= q->coeff ;
            newnode->expo=q->expo;
            newnode->next=NULL;
           
    if(head==NULL)
    {
        head=newnode;
        r=head;
    }
    else{
        r->next=newnode;
        r=newnode;
    }
     q=q->next;}
 return(head);
    
}

void displaypoly(struct node* head){
    struct node* temp;
    if(head==NULL)
    printf("polynomial is empty");
    else{
        temp=head;
        while(temp->next!=NULL){
            printf("%d x^%d +", temp->coeff,temp->expo);
            temp=temp->next;

        }
        printf("%dx^%d\t",temp->coeff,temp->expo);
    }

}


void main(){
    printf("enter the details of first polynomial\n");
    phead=readpoly();

    printf("enter the details of the second polynomial\n");
    qhead=readpoly();
    printf("first\n ");
    displaypoly(phead);
    printf("second\n");
    displaypoly(qhead);
    rhead= addpoly();
    printf("resultant polynomial");
    displaypoly(rhead);

}
