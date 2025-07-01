// find the index of target 

#include<iostream>
using namespace std;
int searchB(int arr[], int si, int ei, int target){

    if(si > ei){
        return -1;
    }

    int mid = si + (ei-si)/2;
    if(arr[mid] == target){
        return mid;
    }
 
    if(arr[si] < arr[mid]){
        if(arr[si] <= target && target <= arr[mid]){
           return searchB(arr, si, mid-1,target);
        }
        else{
           return searchB(arr, mid+1, ei, target);
        }
    }

    else{
        if(arr[mid] <= target && target <= arr[ei]){
          return  searchB(arr,  mid+1, ei, target);
        }
        else{
          return  searchB(arr, si, mid-1, target);
        }
    }
    
}
int main()
{
   int arr[] = {4,5,6,7,0,1,2};
   int n = sizeof(arr) / sizeof(int);
   cout<<searchB(arr, 0, n-1, 0);
   return 0;
}