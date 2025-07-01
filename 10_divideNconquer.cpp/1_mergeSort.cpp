#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[], int si, int mid, int ei){   // conquer
    vector<int> temp;
    int i = si;
    int j = mid+1;

    while(i<=mid && j<=ei){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        if(arr[i] >= arr[j]){
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=ei){
        temp.push_back(arr[j]);
        j++;
    }

    for(int idx=si, x=0;idx<=ei;idx++,x++){
        arr[idx] = temp[x];
    }
    
}
 
void mergeSort(int arr[], int si, int ei){   // si -> starting Index     ei -> ending index

    if(si>=ei){
        return ;
    }
    int mid = si +(ei-si) / 2 ;    // same as  (si + ei) / 2

    mergeSort(arr, si, mid);  //  left index
    mergeSort(arr, mid+1, ei);  // right index
    merge(arr,si,mid,ei);
}

void printArr(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main()
{
   int arr[] = {12,31,3,52,45,67};
   int n = sizeof(arr) / sizeof(int);

   mergeSort(arr, 0, n-1);
   printArr(arr, n);
   return 0; 
}