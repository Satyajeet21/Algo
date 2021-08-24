#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selectionSort(int arr[], int n)
{
    int indexOfMin, temp;
    printf("Running Selection Sort.\n");
    for (int i = 0; i < n-1; i++)
    {
        indexOfMin = i;
        for (int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[indexOfMin])
            {
                indexOfMin = j; //updating the index of minimum element
            }
        }
        // Swap arr[i] and arr[indexOfMin]
        temp = arr[i];
        arr[i] = arr[indexOfMin];
        arr[indexOfMin] = temp;
    }
}

void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void ReverseSort(int arr[], int n)
{
    int i,j,t;
    for(i=0;i<n/2;i++)
    {
        swap(&arr[i],&arr[n-i-1]);
    }
}

void main()
{
    int n;
    printf("Roll Number - 1929045 ");
    printf("\n");
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%100000;
    }
    clock_t begin=clock();
    //printArray(arr,n);
    selectionSort(arr,n);
    //printArray(arr,n);
    clock_t end=clock();
    float time1=end-begin;

    clock_t initial = clock();
        selectionSort(arr, n);
     clock_t final = clock();
    float sorted_time = final-initial;

    ReverseSort(arr, n);
    clock_t begin_045 = clock();
    selectionSort(arr,n);
    clock_t end_045=clock();
    float reverse_time=end_045-begin_045;
     printf("\n");

    printf("aRndom Time(Average Case) = %f\n",time1);
     
     printf("Reverse Time(Worst Case)= %f\n",reverse_time);

    printf("Sorted Time(Best Case) = %f \n",sorted_time);
}