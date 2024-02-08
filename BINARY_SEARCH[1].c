#include<stdio.h>
#define MAX 10
void bubbleSort(int arr[MAX],int size);
int binarySearch(int arr[MAX],int left, int right, int se);
int main(){
    int se,arr[MAX],size;
    printf("Enter the size of the array:");
    scanf("%d",&size);
    printf("Enter the elements of the array:");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    bubbleSort(arr,size);
    for(int j=0;j<size;j++){
        printf("[%d] ",arr[j]);
    }
    printf("\nEnter the element to be searched:");
    scanf("%d",&se);
    int left = 0;
    int result  = binarySearch(arr, left, size,se);
    if(result !=1){
        printf("Element found at index %d",result);
    }else{
        printf("Element not found.");
    }
    return 0;
}




void bubbleSort(int arr[MAX],int size){
    int temp,swapped;
    for(int i=0;i<size-1;i++){
        swapped=0;
        for(int j=0;j<size-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped=1;
            }
        }
        if(swapped==0){
        break;
    }
    }
}

int binarySearch(int arr[MAX],int left, int right, int se){
    while(left<=right){
        int mid = left+ (right-left)/2;
        if(arr[mid]==se){
            return(mid);
        }
        if(se <arr[mid]){
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
}
