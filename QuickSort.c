#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)      
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } 
    while (i < j);

    // Swapping A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort045(int A[], int low, int high)
{
    int partitionIndex; // Index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(A, low, high); 
        quickSort045(A, low, partitionIndex - 1);  // sort left subarray 
        quickSort045(A, partitionIndex + 1, high); // sort right subarray
    }
}

void swap045(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void ReverseSort(int arr[], int n)
{
    int i;
    for(i=0;i<n/2;i++)
    {
        swap045(&arr[i],&arr[n-i-1]);
    }
}

void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
        printf("%d  ",arr[i]);
        printf("\n");
}

void main()
{    clock_t final, initial;
    int n;
    printf("Roll Number - 1929045 ");
    printf("\n");
    printf("Enter the size of array : ");
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%100;
    }
       
  
//Average//random
    initial=clock(); //clock starts
    //printArray(arr, n);  // random element le liya
        quickSort045(arr, 0, n-1); //sorted
    //printArray(arr, n);  // prints sorted array
    final=clock(); // clock ends
     float avg_time=final -initial;
     printf("\n");

//Worst
    ReverseSort(arr, n);
    initial = clock();
    // printArray(arr, n);
        quickSort045(arr, 0, n-1);
    // printArray(arr, n);
    final=clock();
    float reverse_time= final-initial;
     printf("\n");

//Best
    initial = clock();
    //printArray(arr, n);
        quickSort045(arr, 0, n-1);
    //printArray(arr, n);
    final = clock();
    float sorted_time = final-initial;


    printf("Random Time(Average Case) = %f\n",avg_time);
    
    printf("Reverse Time(Worst Case)= %f\n",reverse_time);

    printf("Sorted Time(Best Case) = %f \n",sorted_time);
   
}
