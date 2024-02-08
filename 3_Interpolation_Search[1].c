/*Take an array as input and search an element in that array using interpolation search.*/

/*NOTE:- Sorting is compulsory before searching an element and elements of the array should
be uniformally distributed.*/

#include <stdio.h>
#define MAX 10

void doSort(int arr[], int n);
int InterpolationSearch(int arr[], int n, int target);

int main()
{
    int i, n, target, arr[MAX];
    printf("Enter the size of the matrix:");
    scanf("%d", &n);
    printf("Enter the elements of the aray:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be searched:");
    scanf("%d", &target);
    doSort(arr, n);
    int result = InterpolationSearch(arr, n, target);
    if (result != -1)
        printf("Element found at the index:%d", result);
    else
        printf("Element not found int the array.");
}
void doSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int InterpolationSearch(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;

    while (left <= right && target >= arr[left] && target <= arr[right])
    {

        int pos = left + ((target - arr[left]) * (right - left)) / (arr[right] - arr[left]);
        //interpolation formula remember it

        if (target == arr[pos])
        {
            return pos;
        }
        if (target < arr[pos])
        {
            right = pos - 1;
        }
        else
        {
            left = pos + 1;
        }
    }
    return -1;
}