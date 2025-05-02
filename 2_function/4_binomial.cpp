#include<iostream>
using namespace std;
int fact(int n){
    if(n==0 || n==1){
        return 1;
    }
    return fact(n-1)*n;
}

int bino(int n, int r){
    return fact(n) / (fact(n-r) * fact(r));
}

int main()
{
    cout<<bino(5,2);
   return 0;
}