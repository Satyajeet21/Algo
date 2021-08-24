#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertionSort(int arr[], int n){
    int current, j;
   
    for (int i = 1; i <= n-1; i++)
    {
        current = arr[i];
        j = i-1;
        
        while(j>=0 && arr[j] > current){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
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

void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
        printf("%d  ",arr[i]);
        printf("\n");
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
        arr[i]= rand()%100;
    }

//Average
    float begin=clock();
        printArray(arr, n);
        insertionSort(arr,n);
            printArray(arr, n);
    float end=clock();
    float time1= end-begin;

//Best
    int initial = clock();
        printArray(arr, n);
        insertionSort(arr, n);
            printArray(arr, n);
    int final = clock();
    float sorted_time = final-initial;

//Worst
    ReverseSort(arr, n);
    
    int begin_045 = clock();
        printArray(arr, n);
        insertionSort(arr,n);
            printArray(arr, n);
    int end_045=clock();
    float reverse_time= end_045-begin_045;
     printf("\n");

    printf("Random Time(Average Case) = %f\n",time1);
     
     printf("Reverse Time(Worst Case)= %f\n",reverse_time);

    printf("Sorted Time(Best Case) = %f \n",sorted_time);
}