#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void majorityElement(vector<int> nums){
    unordered_map<int, int> m;

    for(int i=0;i<nums.size();i++){
        if(m.count(nums[i])){     // 1  means exist
            m[nums[i]]++;
        }
        else{
            m[nums[i]] = 1;
        }
    }

    for(pair<int, int> p : m){
        if(p.second > nums.size()/3 ){
            cout<<p.first<<endl;
        }
    }
}
int main()
{
   vector<int> num1 = {1, 3, 2, 5, 1, 3, 1, 5 , 1};
   vector<int> num2 = {1, 2};

   majorityElement(num1);
   //majorityElement(num2);

   return 0;
}