#include<iostream>
#include<vector>
using namespace std;
void sumPair(vector<int> arr, int target){
    int i=0,j=arr.size()-1;
    while(i<j){
        if((arr[i] + arr[j]) == target ){
            cout<<"sum pair found at "<<i<<" ,"<<j<<endl;
            return;
        }
        else if((arr[i] + arr[j]) > target){
            j--;
        }
        else{
            i++;
        } 
    }
    cout<<"not found";
    return;
}
int main()
{
   vector<int> arr = {2,7,11,15};
   sumPair(arr, 25);
   return 0;
}