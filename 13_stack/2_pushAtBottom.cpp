#include<iostream>
#include<stack>
using namespace std;

void pushAtBottom(stack<int> &st,int val){
    if(st.empty()){
        st.push(val);
        return;
    }

    int temp = st.top();
    st.pop();
    pushAtBottom(st,val);
    st.push(temp);
}

int main()
{
   stack<int> st;
   st.push(1);
   st.push(2);
   st.push(3);
   st.push(4);
   st.push(5);
   
   while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
   }
   cout<<endl;
    pushAtBottom(st, 6);
    cout<<endl;

    while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
   }

   return 0;
}