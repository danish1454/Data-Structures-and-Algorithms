#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

int main()
{
   unordered_map< string, int> m;
   m["india"] = 150;
   m["japan"] = 250;
   m["russia"] = 120;
   m["USA"] = 90;

   for(pair<string, int> country : m){
    cout<<country.first<<", "<<country.second<<endl;
   }

   cout<<endl;
   
   if(m.count("japan")){         // count fun is like search function   1->exists
    cout<<"japan exists \n";
   }
   else{
    cout<<"japan doesn't exists \n";
   }
   
   m.erase("japan");
   
    if(m.count("japan")){         // count fun is like search function   1->exists
    cout<<"japan exists \n";
   }
   else{
    cout<<"japan doesn't exists \n";
   }
   return 0;
}