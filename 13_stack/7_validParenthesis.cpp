#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool isValid(string str){
    stack<char> st;
    
    for(int i=0;i<str.size();i++){
        char curr = str[i];
        if(curr == '(' || curr == '[' || curr == '{'){
            st.push(curr);
        }
        else{  // closing
            if(st.empty()){
                return false;
            }
            if(st.top() == '(' && curr == ')' || st.top() == '[' && curr == ']' || st.top() == '{' && curr == '}' ){
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    return st.empty();
}
int main()
{
   string st1 = "[{()}]";
   string st2 = "{()(}})}";
   cout<<isValid(st1);
   cout<<endl;
   cout<<isValid(st2);

   return 0;
}