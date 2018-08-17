#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <list>
#include <queue>
#include <unordered_map>
using namespace std;

int main(){
    // Vectors
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    cout << "v[0]: " << v[0] << endl;
    cout << "v.size(): " << v.size() << endl;

    // Lists
    list<int> l;
    l.push_front(1);
    l.push_back(2);
    cout << "l.size(): " << l.size() << endl;
    cout << "l.front(): " << l.front() << endl;

    // Stacks
    stack<int> s;
    s.push(1);
    s.push(2);
    cout << "s.top(): " << s.top() << endl;
    cout << "s.size(): " << s.size() << endl;
    s.pop();
    s.pop();
    cout << "s.empty(): " << s.empty() << endl;

    // Queues
    queue<int> q;
    q.push(4);
    q.push(5);
    cout << "q.front(): " << q.front() << endl;
    q.pop();

    // Unordered map
    unordered_map<string, bool> student;
    student["james"] = false;
    student["betty"] = true;
    cout << "student[\"james\"]: " << student["james"] << endl;
    cout << "student[\"betty\"]: " << student["betty"] << endl;
    cout << "student[\"jill\"]: " << student["jill"] << endl;
}
