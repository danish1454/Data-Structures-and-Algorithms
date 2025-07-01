#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

void unionFun(vector<int> arr1, vector<int> arr2){
    unordered_set<int> set;
    for(int i=0;i<arr1.size();i++){
        set.insert(arr1[i]);
    }
    for(int i=0;i<arr2.size();i++){
        set.insert(arr2[i]);
    }
    for(auto el : set){
        cout<<el<<" ";
    }
    return;
}

void intersection(vector<int> arr1, vector<int> arr2){
    unordered_set<int> set;
    for(int el : arr1){
        set.insert(el);
    }
    for(int el : arr2){
        if(set.end() != set.find(el)){
            cout<<el<<" ";
        }
    }
    cout<<endl;
}

int main()
{
   vector<int> arr1 = {1, 3, 5 ,2, 7, 9};
   vector<int> arr2 = {1, 4, 5, 6, 8};
   //unionFun(arr1, arr2);
   intersection(arr1, arr2);
   return 0;
}