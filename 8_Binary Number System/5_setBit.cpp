#include<iostream>
using namespace std;
int setBit(int n, int i){
    int mask = 1 << i;
    return (n | mask);  
   
}
int main()
{
   cout<<setBit(6,3);
   return 0;
}