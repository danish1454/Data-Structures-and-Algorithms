#include<iostream>
#include<vector>
using namespace std;
class Stack{
    vector<int> vec;
    public:
    void push(int val){
        vec.push_back(val);
    }
    
    void pop(){
        vec.pop_back();
    }
    int top(){
        int IDX = vec.size()-1;
        return vec[IDX];
    }
};

int main()
{
   Stack st;
   st.push(4);
   st.push(3);
   st.push(2);
   st.push(1);
   cout<<st.top();
   st.pop();
   cout<<st.top();
   return 0;
}