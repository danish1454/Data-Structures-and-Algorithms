#include<iostream>
using namespace std;
int larg(int *arr){
    int n = sizeof(arr) / sizeof(int);
    int currMax = arr[0];
    for(int i=1;i<n;i++){
        if(currMax < arr[i]){
            currMax = arr[i];
        }
    }
    return currMax;

}
int main()
{
   int arr[] = {3};
   cout<<larg(arr);
   return 0;
}