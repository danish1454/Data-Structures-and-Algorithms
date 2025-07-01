#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

int main()
{
   unordered_set<int> set;

   set.insert(1);
   set.insert(7);
   set.insert(3);
   set.insert(5);
   set.insert(1);     // duplicate values are not added to set, neither changes the size of set

   cout<<set.size()<<endl;

   if(set.find(7) != set.end()){
    cout<<"7 exists\n";
   }
   else{
    cout<<"7 doesn't exists"<<endl; 
   }

   for(auto el : set){
    cout<<el<<" ";
   }
   return 0;
}