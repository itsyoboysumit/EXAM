//Bubble short
#include <stdio.h>
#define max 10

void bubbleSort(int *arr,int n);

int main(){
    int arr[max],n;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    printf("Enter the elements of the array:");
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    bubbleSort(arr,n);
    for (int i=0;i<n;i++){
        printf("[%d] ",arr[i]);
    }
    return 0;
}

void bubbleSort(int *arr,int n){
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}