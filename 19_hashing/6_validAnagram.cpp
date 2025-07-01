#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

bool validAnagram(string s, string t){
    if(s.size() != t.size()){
        return false;
    }
    // create unordermap for s
    unordered_map<char, int> map;
    for(int i=0;i<s.size();i++){
        if(map.count(s[i])){
            map[s[i]]++;
        }
        else{
            map[s[i]] = 1;
        }
    }

    // check with 2nd
    for(int i=0;i<t.size();i++){
        if(map.count(t[i])){
            map[t[i]]--;
            if(map[t[i]] == 0){
                map.erase(t[i]);
            }
        }
        else{
            return false;
        }
    } 
    return map.size() == 0;
}
int main()
{
   string s = "care";
   string t = "race";
   cout<<validAnagram(s, t);
   return 0;
}