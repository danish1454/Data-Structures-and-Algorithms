#include<iostream>
using namespace std;

int main()
{
   int size;
   cin>>size;
   int x=1;
   int *arr = new int[size];

   for(int i=0;i<size;i++){
    arr[i] = x;
    cout<<arr[i]<<" ";
    x++;
   }
   return 0;
} 