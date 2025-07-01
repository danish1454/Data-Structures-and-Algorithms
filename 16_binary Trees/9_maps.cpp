#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
   map<int, string> m;
   
   m[101] = "danish";
   m[102] = "ritish";
   m[103] = "ravi";
   m[105] = "sulakshana";

   cout<<m[101]<<endl;
    cout<<m.count(101)<<endl;    // 1 if some value is present      0 if no value is present

    // loop on maps
    for(auto it : m){   // it is just itterator,   can use 'i'
        cout<<"key = "<<it.first<<" value = "<<it.second<<endl;
    }
    return 0;
}