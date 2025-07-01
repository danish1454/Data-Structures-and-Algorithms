#include<iostream>
using namespace std;
int getBit(int n, int i){
    int mask = 1<<i;
    if(mask & n){
        return 1;
    }
    else{
       return 0;
    }
}
int main()
{
  cout<<getBit(6,1);
   return 0;
}