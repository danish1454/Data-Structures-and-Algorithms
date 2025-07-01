// in this , we can climb eitther 1 or 2 stairs, find ways to complete 

#include<iostream>
#include<vector>
using namespace std;

int climbStairsRec(int n){
    if(n==1 || n==0){
        return 1;
    }
    return climbStairsRec(n-1) + climbStairsRec(n-2);
}

int climbMem(int n, vector<int> &dp){     // O(n)
    if(n==0 || n==1){
        return 1;
    }

    if(dp[n] != -1){
        return dp[n];        
    }

    dp[n] = climbMem(n-1, dp) + climbMem(n-2, dp);
    return dp[n];
}

int climbTab(int n){           // O(n)
    vector<int> dp (n+1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main()
{
    int n=5;
    vector<int> dp(n+1, -1);
   cout<<climbMem(n, dp)<<endl;
   cout<<climbTab(n)<<endl;
   return 0;
}