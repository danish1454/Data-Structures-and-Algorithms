#include<iostream>
#include<stack>
using namespace std;
string reverseString(string str){
    stack<char> st;
    string ans;
    for(int i=0;i<str.size();i++){
        st.push(str[i]);
    }
    while(!st.empty()){
        ans = ans + st.top();
        st.pop();
    }
    return ans;
}
int main()
{
   string name = "hsinad";
   cout<<reverseString(name);
   return 0;
}