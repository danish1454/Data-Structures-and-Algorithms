#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Row{
    public :
    int count; // solder count
    int idx;

    Row(int count, int idx){
        this->count = count;
        this->idx = idx;
    }

    bool operator < (const Row &obj) const {  //minHeap
        if(obj.count == this->count){
            return this->idx > obj.idx;
        }
        return this->count > obj.count;
    }
};

void weakestSolder(vector<vector<int>> matrix, int k){
    vector<Row> row;
    for(int i=0;i<matrix.size();i++){
        int count=0;
        for(int j=0;j<matrix[i].size() && matrix[i][j] == 1;j++){
            count++;
        }
        row.push_back(Row(count, i));
    }
    priority_queue<Row> pq(row.begin(), row.end());

    for(int i=0;i<k;i++){
        cout<<"weakest Solder : "<<pq.top().idx<<endl;
        pq.pop();
    }
}
int main()
{
   vector<vector<int>> matrix = {{1, 0, 0, 0}, {1, 1, 1, 1}, {1, 0, 0, 0}, {1, 0, 0, 0}};
   weakestSolder(matrix, 2);
   return 0;
}