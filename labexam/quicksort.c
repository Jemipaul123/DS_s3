#include <stdio.h>
int size,low, high, A[100]; int pivot_item;
void swap(int x,int y)
{
    int t = x;
    x=y;
    y=t;
}
 int Quicksort(int A,int low, int high){

if(high>low)
{pivot_item = Partition(A,low,high);
Quicksort(A, low, pivot_item-1);
Quicksort(A, pivot_item+1,high);
}

}

int Partition(int A[],int low,int high)
{
   

pivot_item=A[low];
int left=low;
int right=high;
while(left<right)
{while(A[left]<=pivot_item)
{left++;}
while(A[right]>= pivot_item)
{
    right--;}
if (left<right)
swap(left,right);

}

A[low]=A[right];
A[right]=pivot_item;
return right;
}

int main()
{  low=0; high=size-1;
    printf("enter the size");
    scanf("%d",&size);
    printf("enter the elements");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&A[i]);
    }
 Quicksort(A, low ,high);
printf("the elements are");
for(int i=0;i<size;i++)
{
    printf("%d ",A[i]);
}
}
