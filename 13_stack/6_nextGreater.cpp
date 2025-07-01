#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void nextGreater(vector<int> &arr, vector<int> &ans){
    stack<int> st;
    int IDX = arr.size()-1;
    ans[IDX] = -1;
    st.push(arr[IDX]);
    
    for(IDX = IDX-1;IDX>=0;IDX--){
        while(!st.empty() && st.top() <= arr[IDX]){
            st.pop();
        }
        if(st.empty()){
            ans[IDX] = -1;
        }
        else{
            ans[IDX] = st.top();
        }
        st.push(arr[IDX]);
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
int main()
{
   vector<int> arr = {6,8,0,1,3};
   vector<int> ans = {0,0,0,0,0};
   nextGreater(arr, ans);
   return 0;
}