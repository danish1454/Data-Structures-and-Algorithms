#include<iostream>
#include<vector>

using namespace std;
class Heap{
public :
vector<int> vec;

void push(int val){ 
    // pushBack value
    vec.push_back(val);

    // fix heap
    int x = vec.size()-1; // childIndex
    int parI = (x-1)/2;  // parent index
 
    while(parI >=0 && vec[x] > vec[parI]){           // for min heap   vec[x] < vec[parI]
        swap(vec[x], vec[parI]); 
        x = parI;
        parI = (x-1)/2;
    } 
}

int top(){
    return vec[0];
}

bool empty(){
    return vec.empty();
}
};
int main()
{
   Heap heap;
   heap.push(30);
   heap.push(56);
   heap.push(12);
   heap.push(22);

   cout<<heap.top();
   return 0;
}