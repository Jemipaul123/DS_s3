

void selection sort(){
    int i,j temp;
    for(int i=0;i<n-1;i++)
    {
        min=i;
        for(int j=0;j<n-1;j++)
        {
            if(arr[j]<arr[min]){
                min=j;
               

            }
        }
        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
        }
