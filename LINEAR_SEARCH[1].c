#include<stdio.h>
#define MAX 10

int linearSearch(int arr[MAX],int se,int n);
int main(){
    int arr[MAX],se,n;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    printf("Enter the elements to be inserted in the array:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be searched:");
    scanf("%d",&se);
    int result = linearSearch(arr,se,n);
    if(result !=0){
        printf("Element foundat at %d index.",result);
    }else{
        printf("Not found.");
    }
    return 0;

}
int linearSearch(int arr[MAX], int se, int n){
    for(int i=0;i<n;i++){
        if(se==arr[i]){
            return (i);
        }
    }
    return 0;
}