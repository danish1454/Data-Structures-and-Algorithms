#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.second > p2.second;
}

int maxProfit(vector<pair<int, int>> pairs){
    sort(pairs.begin(), pairs.end(), compare);
    // first-> deadline     second-> profit

    int maxProfit = pairs[0].second;
    int currDeadline = 2;   // since we selected 1st job, 1st job will take 1 unit, so safedeadline is 2 as at 2 we can take another job, not at 1
    for(int i=1;i<pairs.size();i++){
        if(pairs[i].first >= currDeadline){
            maxProfit += pairs[i].second;
            currDeadline++;
        }
    }
    return maxProfit;

}

int main()
{
    int n = 4;
    vector<pair<int, int>> pairs(n, make_pair(0, 0));
    pairs[0] = make_pair(4, 20);
    pairs[1] = make_pair(1, 10);
    pairs[2] = make_pair(1, 40);
    pairs[3] = make_pair(1, 30);
    
    cout<<maxProfit(pairs);
   return 0;
}