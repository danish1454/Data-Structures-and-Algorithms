// priority queue are alsso known as heap
// to use pq, we include queue and the     priority_queue<int> pq

//  in heap  to find chld of a parent  ->  2*i + 1(left)  and 2*i + 2(right)           'i' is the index in vector represent
// for parent from child  -> (x-1)/2   
#include<iostream>
#include<queue>
using namespace std;

int main()
{
   priority_queue<int> pq1;                                          // max heap
   priority_queue<int, vector<int>, greater<int>> pq2;               // min heap
   pq1.push(0);
   pq1.push(7);
   pq1.push(3);
   pq1.push(8);
   pq1.push(6);

   while( !pq1.empty()){
    cout<<pq1.top();
    pq1.pop();
    cout<<endl;
   }
   cout<<endl;

   pq2.push(0);
   pq2.push(7);
   pq2.push(3);
   pq2.push(8);
   pq2.push(6);

   while( !pq2.empty()){
    cout<<pq2.top();
    pq2.pop();
    cout<<endl;
   }
   cout<<endl;
   return 0;
}