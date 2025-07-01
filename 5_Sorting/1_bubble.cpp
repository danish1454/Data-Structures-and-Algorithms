#include<iostream>
using namespace std;
void sort(int arr[], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[j+1] < arr[j] ){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }     
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main()
{
   int arr[] = {2,5,712,4,52,3};
   int n =sizeof(arr)/sizeof(int);
   sort(arr,n);
   return 0;
}