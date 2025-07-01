#include<iostream>
#include<vector>
using namespace std;
int main()
{
   vector< vector<int> > matrix = {{1,2,3}, {4,5,6},{7,8,9}};    // format for 2D matrix  // Rows and Col can be of diff size in 2D matrix using vectors 
   
   for(int i=0;i<matrix.size();i++){
    for(int j=0;j<matrix[i].size();j++){
        cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
   }
   return 0;
}