#include<iostream>
using namespace std;
void printP(int n){
    char ch = 'A';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<ch;
            ch++;
        }
        cout<<endl;
    }
}
int main()
{
   printP(5);
   return 0;
}