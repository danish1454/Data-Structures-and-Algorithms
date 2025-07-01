#include<iostream>
#include<vector>
using namespace std;
int main()
{
   vector<int> v1;
   vector<int> v2 = {1,2,3,4,5};
   vector<int> v3(10, -1);      //(size, value)  => {-1,-1,-1, ......}
   
   for(int i=0;i<v3.size();i++){
    cout<<v3[i]<<" ";
   }
   return 0;
}