#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(int n){
    int a  = floor(sqrt(n));
    for(int i=1;i<=a;i++){
        if(n%i == 0){
            cout<<"prime"<<endl;
            return 1;
        }
    }
    cout<<"not prime"<<endl;
    return 0;
}
int main()
{
   cout<<isPrime(13);
   return 0;
}