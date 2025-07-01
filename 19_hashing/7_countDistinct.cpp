#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int countDistinct(vector<int> nums){
    unordered_set<int> s;
    for(int i=0;i<nums.size();i++){
        s.insert(nums[i]);
    }
    return s.size();
}
int main()
{
   vector<int> nums = { 3, 5, 23, 6, 53, 62, 9, 34, 7, 9 ,9 ,3 ,6};
   cout<<countDistinct(nums);
   
   return 0;
}