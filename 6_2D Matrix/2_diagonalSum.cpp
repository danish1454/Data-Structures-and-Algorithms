#include<iostream>
using namespace std;
int diagonalSum(int arr[][4], int n){   // O(N^2)
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == j){
                sum += arr[i][j];
            }
            else if(j == n-i-1){
                sum += arr[i][j];
            }
        }
    }

    return sum;
}

int diagonalSum2(int arr[][3], int n){              //  O(N)
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i][i];   // primary diogonal
        if(i != n-i-1){
            sum += arr[i][n-i-1];   // secondary diagonal
        }
    }
    return sum;
}

int main()
{
   int matrix[4][4] ={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
   cout<<diagonalSum(matrix, 4)<<endl;

   int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
   cout<<diagonalSum2(arr,3);
   return 0;
}