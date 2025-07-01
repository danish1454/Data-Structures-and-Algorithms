// Binary String problem : no concecutive 1 should be print

#include<iostream>
#include<string>
using namespace std;


void binaryString(int n, int lastDigit, string ans){

    if(n==0){
        cout<<ans<<" ";
        return;
    }

    
    if(lastDigit!=1){
        binaryString(n-1, 0, ans+'0');
        binaryString(n-1, 1, ans+'1');
    }
    else{
        binaryString(n-1, 0, ans+'0');
    }
}

void binaryString2(int n, string ans){            // Method 2

    if(n==0){
        cout<<ans<<" ";
        return;
    }

    
    if(ans[ans.size()-1] != 1 ){
        binaryString2(n-1, ans + '0');
        binaryString2(n-1, ans + '1');
    }
    else{
        binaryString2(n-1, ans+'0');
    }
}

int main()
{
    string ans = " ";
   binaryString2(4, ans);
   return 0;
}