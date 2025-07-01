#include<iostream>
using namespace std;
int clearLast(int n, int i){
    int mask = ~0 << i;                      // ~0 = 11111111

    return mask & n;
}
int main()
{
   cout<<clearLast(15,2);
   return 0;
}