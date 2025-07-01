#include<iostream>
#include<string>
#include<vector>                   
using namespace std;
void subSets(string str, string subsets){

    if(str.size() == 0){
        cout<<subsets<<endl;
        return;
    }

    char ch = str[0];

    // yes
    subSets(str.substr(1, str.size()-1), subsets + ch);

    // no
    subSets(str.substr(1, str.size()-1), subsets);

}
int main()
{
   string str = "abc";
   string ans ="";
   subSets(str,ans);
   return 0;
}