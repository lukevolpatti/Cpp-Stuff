#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> q;
    q.push(5);
    q.push(6);
    q.push(7);

    cout << "size: " << q.size() << endl;
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();

    cout << "Priority queue: " << endl;
    priority_queue<int> p;
    p.push(6);
    p.push(5);
    p.push(7);
    cout << p.top() << endl;
}
