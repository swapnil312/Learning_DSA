# include <stdio.h>
int linearSearch(int arr[], int size,int element)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == element)
        {
            return i;
        }
    }
    
    return -1;
}
int binarySearch(int arr[], int size, int element){
    int low = 0;
    int high = size-1;
    int mid = (low+high)/2;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(arr[mid] == element)
        {
            return mid;
        }
        if(arr[mid] < element)
        {
            low = mid+1;

        }
        else
        {
            high = mid-1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {3,54,786,34,67,34,67,54,34,8,478,67,5434,67,3};
    int arr1[] = {2,3,5,7,9,9,10,11,14,465};
    int size = sizeof(arr)/sizeof(int);
    int element = 10568;
    int searchIndex = linearSearch(arr, size, element);
    printf("Element %d was found at %d.",element,searchIndex);
    int element1 = 9;
    int size1 = sizeof(arr1)/sizeof(int);
    int searchIndex1 = binarySearch(arr1,size1,element1);
    printf("\nElement %d was found at %d.",element1,searchIndex1);
    return 0;
}