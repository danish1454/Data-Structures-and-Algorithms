#include<iostream>
using namespace std;
int clearBit(int n, int i){
    int mask = ~(1 << i);
    return (mask & n);   // '~' because we will reach iTH pos and then set it to 0, then take '&' 
}
int main()
{
   cout<<clearBit(8,3);
   return 0;
}