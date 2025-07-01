#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void heapify(int i, vector<int> &arr, int n){
    int left = 2*i + 1;
    int right = 2*i + 2;
    int maxI = i;

    if(left < n && arr[left] > arr[maxI]){
        maxI = left;
    }

    if(right < n && arr[right] > arr[maxI]){
        maxI = right;
    }

    if(maxI != i){
        swap(arr[maxI], arr[i]);
        heapify(maxI, arr, n);
    }
}

void heapSort(vector<int> &arr){
    int n = arr.size();

    for(int i=n/2-1; i>=0; i--){            // i is n/2-1 because if we yse formula  child = 2*i _1 , it will go beyond arr 
        heapify(i, arr, n);             // i will be parent address
    }

    for(int i=n-1;i>=0;i--){
        swap(arr[0], arr[i]);
        heapify(0, arr, i);
    }
}

int main()
{
   vector<int> arr = {2,4,1,6,7,5};
   heapSort(arr);
   for(int i=0;i<arr.size();i++){
    cout<<arr[i]<<" ";
   }
   return 0;
}