#include<iostream>
using namespace std;
void oddEven(int n){
    if(n & 1 == 1){
        cout<<"odd"<<endl;
    }
    else{
        cout<<"even";
    }
}
int main()
{
   oddEven(8);
   return 0;
}