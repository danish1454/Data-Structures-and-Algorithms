#include<iostream>
#include<vector>
using namespace std;
int mmaxActivity(vector<int> start, vector<int>end){
    // sort end time       In this question, already sorted
    // A0
    int count = 1;
    int currEndTime = end[0];
    cout<<"selectinf A0"<<endl;

    for(int i=1;i<start.size();i++){
        if(start[i] >= currEndTime){
            cout<<"selecting A"<<i<<endl;
            currEndTime = end[i];
            count++;
        }
    }
    return count; 
}
int main()
{
   vector<int> start = {1,3,0,5,8,5};
   vector<int> end =   {2,4,6,7,9,9};
   cout<<mmaxActivity(start, end);

   return 0;
}