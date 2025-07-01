#include<iostream>
#include<cmath>
using namespace std;
void btd(int n){
    int num=0;
    int temp =n;
    int count =0;
    while(temp>0){
        int ld = temp%10;
            num += ld * pow(2,count);
            count++;
            temp = temp/10;
        }
        cout<<num;
    }

int main()
{
   btd(1001);
   return 0;
}