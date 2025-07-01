#include<iostream>
using namespace std;

int partition(int arr[], int si, int ei){
    int i = si-1;
    int pivot = arr[ei];

    for(int j=si;j<ei;j++){
        if(pivot >= arr[j]){
            i++;
            swap(arr[i], arr[j]);
        }
    }
 
    i++;
    swap(arr[i],arr[ei]);

    return i;   // pivotIDX => i
}

void quickSort(int arr[], int si, int ei){

    if(si>=ei){
        return;
    }

    int pivotIDX = partition(arr, si, ei);
    
    quickSort(arr, si, pivotIDX-1);
    quickSort(arr, pivotIDX+1, ei);
}

void printArr(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main()
{
   int arr[] ={12,434,6,3,546,66};
   int n=6;
   quickSort(arr, 0, n-1);
   printArr(arr, n); 
   return 0;
}