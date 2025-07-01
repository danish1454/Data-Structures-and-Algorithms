#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int maxAreaHistogram(vector<int> height){
    vector<int> nsl(height.size());   // next smaller left
    vector<int> nsr(height.size());  // next smaller right
    stack<int> st;

    // nsl
    nsl[0] =-1;
    st.push(0);   // indices will be used
    for(int i=1;i<height.size();i++){
        int curr = height[i];
        while(!st.empty() && curr <= height[st.top()]){
            st.pop();
        }  
        if(st.empty()){
            nsl[i] = -1;
        }
        else{
            nsl[i] = st.top();
        }
        st.push(i);
    }   
    
    // emptying stack   because we didnt wanted to use another stack
    while(!st.empty()){
        st.pop();
    } 

    // nsr
    int n = height.size();
    st.push(n-1);    // index is used
    nsr[n-1] = n;

    for(int i = n-2; i>=0;i--){
        int curr = height[i];
        while(!st.empty() && curr <=height[st.top()]){
            st.pop();
        }
        if(st.empty()){
            nsr[i] = n;    // not -1
        }
        else{
            nsr[i] = st.top();
        }
        st.push(i);
    }

    int maxArea = 0;
    for(int i=0;i<height.size();i++){
        int ht = height[i];
        int widght = nsr[i] - nsl[i] - 1;
        int area = ht * widght;

        maxArea = max(maxArea , area);
    }

    return maxArea;
}
int main()
{
   vector<int> height = {2,1,5,6,2,3};
   cout<<maxAreaHistogram(height);
   return 0;
}