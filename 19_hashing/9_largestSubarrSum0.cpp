#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int largestSubarrSum0(vector<int> arr){
    unordered_map<int, int> map;  // sum , idx
    int sum = 0;
    int ans = 0;

    for(int j=0; j<arr.size(); j++){
        sum += arr[j];

        if(map.count(sum)){
            int currLen = j-map[sum]; 
            ans = max(currLen, ans);
        }
        else{
            map[sum] = j;
        }
    }
    return ans; 
}

int main()
{
   vector<int> arr = {15, -2, 2, -8, 1, 7, 10};
   cout<<largestSubarrSum0(arr);
   return 0;
}