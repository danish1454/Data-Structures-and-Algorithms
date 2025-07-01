#include<iostream>
#include<string>
using namespace std;
void permutation(string str, string ans){
    if(str.size() == 0){
        cout<<ans<<endl;
        return;
    }

    for(int i=0;i<str.size();i++){

    char ch = str[i];
    string nextStr = str.substr(0, i) + str.substr(i+1, str.size()-i-1);
    permutation(nextStr, ans + ch);
    }
        

}
int main()
{
   string ans = " ";
   string str = "abc";

   permutation(str, ans);
   return 0;
}