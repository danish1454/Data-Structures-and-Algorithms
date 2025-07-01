#include<iostream>
using namespace std;
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void sort(int arr[] ,int n){
    for(int i=0;i<n-1;i++){
        int minIDX = i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[minIDX]){
                swap(arr[j], arr[minIDX]);
            }
        }
    }
    print(arr, n);
}
int main()
{
   int arr[] = {5,4,3,2,1};
   sort(arr, 5);
   return 0;
}