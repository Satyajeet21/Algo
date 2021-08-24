#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main()
{
    int n;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%10;
    }
    float begin=clock();
    bubble_sort(arr,n);
    float end=clock();
    float time1=end-begin;

    int initial = clock();
    bubble_sort(arr, n);
    int final = clock();
    float sorted_time = final-initial;
     int start = 0, stop = n-1;
     while(start<=stop)
     {
         int temp=arr[start];
         arr[start]=arr[stop];
         arr[stop]=temp;
         start++;
         stop--;
     }
    int begin_045 = clock();
    bubble_sort(arr,n);
    int end_045=clock();
    float reverse_time=end_045-begin_045;
      printf("\n");
    printf("Random Time = %f\n",time1);
     printf("Sorted Time = %f \n",sorted_time);
     printf("Reverse Time= %f\n",reverse_time);
}

void bubble_sort(int arr[],int n)
{

    for(int i=0;i<n-1;i++)
    {
       for(int j=0;j<n-1;j++)
       {
           if(arr[j]>arr[j+1])
           {
               int temp=arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=temp;
           }
       }
    }

}


