#include<iostream>
#include<vector>
#include<algorithm>
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

//we want to sort on basis on ending value
bool compare(pair<int, int> p1, pair<int, int> p2){    // pair(starting, end)   and we are comparing some 2 pairs ata time
    return p1.second < p2.second;  //ascending (we use <)  // for descinding (we use >)    just learn it !!!    
}

int main()
{      // pairs ka syntax hai ye    zyada backchodi nhi
   vector<int> start = {0,1,2};
   vector<int> end =   {9,2,4};
   // cout<<mmaxActivity(start, end);

   vector<pair<int, int>>acivities(3, make_pair(0,0));     // make_pair is cumoporsary  // it is a vector of pairs 
   acivities[0] = make_pair(0,9);
   acivities[1] = make_pair(1,2);
   acivities[2] = make_pair(2,4);

    for(int i=0;i<acivities.size();i++){
        cout<<acivities[i].first<<","<<acivities[i].second<<endl;
    }

    sort(acivities.begin(), acivities.end(), compare); // we define this compare fun, can be of any name
    cout<<"-------------------------sorted-------------------"<<endl;
    for(int i=0;i<acivities.size();i++){
        cout<<acivities[i].first<<","<<acivities[i].second<<endl;
    }
   return 0;
}