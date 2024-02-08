// Quick shorting
#include <stdio.h>
#define MAX 10

void quickSort(int *a,int low, int high);
int split(int *a, int low, int high);

int main(){
    int arr[MAX],n;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    printf("Enter the elements of the array:");
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quickSort(arr,0,n-1);
    for (int i=0;i<n;i++){
        printf("[%d] ",arr[i]);
    }
    return 0;

}

void quickSort(int *a, int low, int high)
{
    if (low < high)
    {
        int p = split(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}
int split(int *a, int low, int high)
{
    int pivotValue = a[low];
    int i = low + 1;
    int j = high;
    while (i < j)
    {
        while (a[i] < pivotValue)
            i++;
        while (a[j] > pivotValue)
            j--;
        if(i<j){
            int t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    int t=a[low];
    a[low]=a[j];
    a[j]=t;
    return (j);
} 