// Important question : Tiling Problem


#include<iostream>
using namespace std;
int tp(int n){
    if(n==0){     // Not placing a tile is also a way o placing a tile 
        return 1;    
    }
    if(n==1){
        return 1;
    }
    return tp(n-1) + tp(n-2);
}
int main()
{
   std::cout<<tp(4);
   return 0;
}