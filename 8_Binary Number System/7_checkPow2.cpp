#include<iostream>
using namespace std;
bool checkPow(int n){
    if ( !(n & n-1) ){
        return 1;
    }
    return 0;
}
int main()
{
   cout<<checkPow(64);
   return 0;
}