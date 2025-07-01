#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

class Student{
    public:
    string name;
    int marks;

    Student(string name, int marks){
        this->name = name;
        this->marks = marks;
    }

    bool operator < (const Student &obj) const {
        return this->marks < obj.marks;        
    }

};

int main()
{
   priority_queue<Student> pq;
   pq.push(Student("name1", 86));
   pq.push(Student("name2", 90));
   pq.push(Student("name3", 45));
   pq.push(Student("name4", 78));
   pq.push(Student("name5", 74));

   while(!pq.empty()){
    cout<<"top :"<<pq.top().name<<", "<<pq.top().marks<<endl;
    pq.pop();
   }
   return 0;
}