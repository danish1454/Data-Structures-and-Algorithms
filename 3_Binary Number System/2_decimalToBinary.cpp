#include<iostream>
#include<cmath>
using namespace std;
void dtb(int n){
    int temp=n, count=0, num=0;
    while(temp){
        int ld = temp%2;
         num = num + ld * pow(10,count);
        count++;
        temp = temp/2;
    }
    cout<<num;
}
int main()
{
   dtb(11);
   return 0;
}