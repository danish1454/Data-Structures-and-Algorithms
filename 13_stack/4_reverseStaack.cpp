#include<iostream>
#include<stack>
using namespace std;
void pushBottom(stack<int> &st, int val){
    if(st.empty()){
        st.push(val);
        return;
    }
    int temp = st.top();
    st.pop();
    pushBottom(st, val);
    st.push(temp);
}

void reverse(stack<int> &st){
    if(st.empty()){
        return;
    }
    int temp = st.top();
    st.pop();
    reverse(st);
    pushBottom(st,temp);
}

int main()
{
   stack<int> st;
   int i=1;
   while(i!=6){
    st.push(i);
    i++;
   }

   reverse(st);

   while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
   }

   return 0;
}