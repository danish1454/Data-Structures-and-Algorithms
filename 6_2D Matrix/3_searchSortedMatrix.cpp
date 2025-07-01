/* 
  Using Stair Case Algorithm

  start from top right or Bottom Left
  if start from top right 
    check if element is bigger then go Down
    if element smaller go left 
*/ 

#include<iostream>
using namespace std;
bool searchMatrix(int arr[][4], int n, int m, int key){
    int i=0, j =m-1;
    while(i<n && j>=0){
        
        if(arr[i][j] == key){
            cout<<"found at "<<i<<", "<<j;
            cout<<endl;
            return true;
        }
        else if(key < arr[i][j]){
            j--;
        }
        else{
            i++;
        }
    }
    return 0;
}
int main()
{
    int matrix[4][4] ={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    cout<<searchMatrix(matrix, 4,4,14);
   return 0;
}