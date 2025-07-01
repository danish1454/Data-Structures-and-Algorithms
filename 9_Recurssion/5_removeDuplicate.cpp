#include<iostream>
#include<string>
using namespace std;
void removeDup(string str, string ans, int i, int map[26]){
    if(i == str.size()){
        cout<<ans<<endl;
        return;
    }
    char ch = str[i];  // ch is a temp variable
    int mapIDX = (int)(ch - 'a');  // That's how to make map index
    
    if(map[mapIDX]== true){  // Duplicate'
    return removeDup(str, ans, i+1, map);
    }    
    else{
        map[mapIDX] = true;
        return removeDup(str, ans + str[i], i+1, map);
    }
}
int main()
{
   int map[26] = {false};
   string ans = "";
   string str = "apnacollege";
   removeDup(str, ans, 0, map);
   return 0;
}


