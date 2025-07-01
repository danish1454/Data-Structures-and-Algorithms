#include<iostream>
using namespace std;
int maxProfit(int *arr, int n){
    int bestBuy[n];
    bestBuy[0] = INT_MAX;

    for(int i=1;i<n;i++){
        bestBuy[i] = min(arr[i], bestBuy[i-1]);
    }

    int maxProfit = 0;
    for(int i=0;i<n;i++){
        int currProfit = arr[i] - bestBuy[i];
        maxProfit = max(currProfit,maxProfit);
    }
    return maxProfit;
}
int main()
{
   int arr[] = {7,1,5,3,6,4};
   int n = sizeof(arr) / sizeof(int);

   cout<<maxProfit(arr, n);
   return 0;
}