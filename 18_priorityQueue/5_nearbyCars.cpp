#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Cars{
    public :
    int idx;
    int distSq;

    Cars(int idx, int distSq){
        this->idx = idx;
        this->distSq = distSq;
    }

    bool operator < (const Cars &obj) const {
        return this->distSq > obj.distSq;  // minHeap
    }
};

void neabyCars(vector<pair<int, int>> pos, int K){
    vector<Cars> cars;
    for(int i=0;i<pos.size();i++){
        int distSq = (pos[i].first * pos[i].first) + (pos[i].second * pos[i].second);
        cars.push_back(Cars(i, distSq));       // thats how we stores idx
    }

    priority_queue<Cars> pq(cars.begin(), cars.end());

    for(int i=0;i<K;i++){
        cout<<"car "<<pq.top().idx<<endl;
        pq.pop();
    }
}

int main()
{
   vector<pair<int, int>> pos;
   pos.push_back(make_pair(3, 3));
   pos.push_back(make_pair(5, -1));
   pos.push_back(make_pair(2, 4));
   neabyCars(pos, 2);
   return 0;
}