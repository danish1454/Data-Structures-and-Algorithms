#include<iostream>
using namespace std;
int binarySearch(int arr[], int n, int key){
    int start = 0;
    int end = n-1;

    while(start<=end){
        int mid = (start + end)/2;
        if(arr[mid] == key ){
            return mid;
        }
        else if(key < arr[mid]){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return -1;
}
int main()
{
   int arr[5] = {2,4,6,8,10};
   int n = sizeof(arr)/ sizeof(int);
   cout<<"element found at "<<binarySearch(arr,n,8)<<"th index";
   return 0;
}