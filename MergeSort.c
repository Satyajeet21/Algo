#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void mergearr(int arr[], int mid, int low, int high)
{
    int i, j, k;
    int B[250000];

     i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            B[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            B[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = arr[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
       arr[i] = B[i];
    }
    
}

void mergeSort(int arr[], int low, int high)
{
    int mid; 
    if(low<high)
    {
        mid = (low + high) /2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        mergearr(arr, mid, low, high);
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
    int i;
    for(i=0;i<n/2;i++)
    {
        swap(&arr[i],&arr[n-i-1]);
    }
}

/*void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
        printf("%d  ",arr[i]);
        printf("\n");
}*/

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
        arr[i]=rand()%10000;
    }
       
    
//Average
    initial=clock();
   // printArray(arr, n);
        mergeSort(arr, 0, n-1);
   // printArray(arr, n);
    final=clock();
     float avg_time=final -initial;
     printf("\n");

//Worst
    ReverseSort(arr, n);
    initial = clock();
  // printArray(arr, n);
        mergeSort(arr, 0, n-1);
   // printArray(arr, n);
    final=clock();
    float reverse_time= final-initial;
     printf("\n");

//Best
    initial = clock();
  //printArray(arr, n);
        mergeSort(arr, 0, n-1);
  // printArray(arr, n);
    final = clock();
    float sorted_time = final-initial;


    printf("Random Time(Average Case) = %f\n",avg_time);
    
    printf("Reverse Time(Worst Case)= %f\n",reverse_time);

    printf("Sorted Time(Best Case) = %f \n",sorted_time);
   
}
