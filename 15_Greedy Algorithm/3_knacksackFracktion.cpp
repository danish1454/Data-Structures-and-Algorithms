//  fraction knapsack is solved using Greedy and                 0,1 knapsack is solved using DP
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<double, int> p1, pair<double, int> p2){
    return p1.first > p2.first;
}

int fractionKnapsack(vector<int> val, vector<int> wt, int W){
    int n = val.size();
    vector<pair<double, int>> ratio(n ,make_pair(0.0, 0));  // pair(raio, idx)  => (double, int)

    for(int i=0;i<n;i++){
        double r = val[i] / (double)wt[i];
        ratio[i] = make_pair(r, i);
    }

    sort(ratio.begin(), ratio.end(), compare);  // descending

    int ans = 0;
    for(int i=0;i<n;i++){
        int idx = ratio[i].second;   // to get the idx of sorted pairs
        if(wt[idx] < W){
            ans += val[idx];
            W -= wt[idx];
        }
        else{
            ans += ratio[i].first * W;
            W = 0;
        }
    }
    return ans;
}

int main()
{
   vector<int> val = {60, 100, 120};
   vector<int> wt =  {10, 20, 30};
   int W = 50;   // max weight
   cout<<fractionKnapsack(val, wt, W);
   return 0;
}