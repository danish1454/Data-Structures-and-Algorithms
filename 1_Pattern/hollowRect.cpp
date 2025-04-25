#include<iostream>
using namespace std;
void printP(int n){
    int i,j;
    for(i=1;i<=n;i++){
        cout<<"*";
        for(j=1;j<=n-1;j++){
            if(i==1 || i==n){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<"*";
        cout<<endl;
    }
}
int main()
{
   printP(4);
   return 0;
}