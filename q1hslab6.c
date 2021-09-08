#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap24(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;  
    *b=temp;
} 

void ReverseSort(int arr[], int n)
{
    for(int i=0;i<n/2;i++)
    {
        swap24(&arr[i],&arr[n-i-1]);
    }
}

void heapify(int arr[], int n,int i)
{   
    int largest = i;
    int lch = 2*i + 1;
    int rch = 2*i + 2;
    
    if(lch < n && arr[lch] > arr[largest])
    {
        largest = lch;
    }

    if(rch < n && arr[rch]> arr[largest])
    {
        largest = rch;
    }

    if(largest !=i)
    {
        swap24(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[],int n)
{
    int i;
    for(i=(n/2 - 1); i>=0; i--)
    {
        heapify(arr,n,i);
    }

    for(i=n-1; i>=0; i--)
    {
        swap24(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}


void main()
{   
     clock_t final, initial;
    int s,f,step;

    printf("Enter starting size: ");
    scanf("%d",&s);
    printf("Enter size of steps: ");
    scanf("%d",&step);
    printf("Enter ending size: ");
    scanf("%d",&f);
    int *arr;
    for(int n=s;n<=f;n+=step)
    {
    printf("\n");
    
    printf("Time Complexity for %d\n",n);
    printf("___________\n");
    arr=(int *)malloc(n * sizeof(int));
    for(int i=0;i<n;i++)
        arr[i]=rand()%10000;
    
    initial=clock();   
    heapSort(arr, n); 
    final=clock(); 
    time_t avg_time=final -initial;

    ReverseSort(arr, n);
    initial = clock();
    heapSort(arr,n);
    final=clock();
    time_t reverse_time= final-initial;

    initial = clock();
    heapSort(arr, n);
    final = clock();
    time_t sorted_time = final-initial;

    printf("Random Time = %d\n",avg_time);
    printf("Reverse Time = %d\n",reverse_time);
    printf("Sorted Time = %d \n",sorted_time);
    free(arr);
    }   
}