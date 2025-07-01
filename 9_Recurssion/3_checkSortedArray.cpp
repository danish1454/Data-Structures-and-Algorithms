#include<iostream>
using namespace std;
bool isSorted(int arr[], int n, int i){
    if(i == n-1){
        return true;
    }
    if(arr[i]<arr[i+1]){
        return isSorted(arr, n, i+1);
    }
    else{
        return false;
    }
}
int main()
{
    int arr1[] = {1,2,3,4,5};
    int arr2[] = {1,2,4,7,3};
   cout<<isSorted(arr1, 5,0);
   cout<<endl;
   cout<<isSorted(arr2, 5, 0);
   return 0;
}