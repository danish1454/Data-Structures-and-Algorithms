#include<iostream>
using namespace std;
int fact1(int n){
    if(n==0 || n==1){
        return 1;
    }
    return fact1(n-1)*n;
}

int fact2(int n){
    int fact = 1;
    for(int i=1;i<=n;i++){
        fact = fact * i;
    } 
    return fact;
}
int main()
{
   cout<<fact1(0);
   return 0;
}