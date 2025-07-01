#include<iostream>
#include<vector>
using namespace std;

int knapSackRec(vector<int> val, vector<int> wt, int W, int n){
    
    if(n==0 || W==0){
        return 0;
    }

    int itemWt = wt[n-1]; 
    int itemVal = val[n-1];

    if(itemWt <= W){
        // include
        int ans1 = knapSackRec(val, wt, W-itemWt, n-1) + itemVal;
        
        // excude
        int ans2 = knapSackRec(val, wt, W, n-1); 

        return max(ans1, ans2);
    }
    else{
        // exclude
        return knapSackRec(val, wt, W, n-1);
    }
}

int knapSackMem(vector<int> val, vector<int> wt, int W, int n, vector<vector<int>> &dp){
    
    if(n==0 || W==0){
        return 0;
    }
    
    if(dp[n][W] != -1){
        return dp[n][W];
    }

    int itemWt = wt[n-1]; 
    int itemVal = val[n-1];

    if(itemWt <= W){
        // include
        int ans1 = knapSackMem(val, wt, W-itemWt, n-1, dp) + itemVal;
        
        // excude
        int ans2 = knapSackMem(val, wt, W, n-1, dp); 

        dp[n][W] = max(ans1, ans2);
        return dp[n][W];
    }
    else{
        // exclude
        dp[n][W] = knapSackMem(val, wt, W, n-1, dp);
        return dp[n][W];
    }
}

int main()
{
   vector<int> val = {15, 14, 10, 45, 30};
   vector<int> wt = {2, 5 ,1, 3, 4};
   int W = 7;
   int n = 5;

   vector<vector<int>> dp(n+1, vector<int>(W+1, -1));

   cout<<knapSackRec(val, wt, W, n)<<endl;
   cout<<knapSackMem(val, wt, W, n, dp)<<endl;
   return 0;
}