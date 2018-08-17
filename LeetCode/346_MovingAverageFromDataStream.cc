#include <iostream>
#include <queue>
using namespace std;

struct MovingAverage{
    int windowSize;
    int totalSum;
    queue<int> q;

    MovingAverage(int size);
    double next(int newNum);
};

MovingAverage::MovingAverage(int size){
    windowSize = size;
    totalSum = 0;
}

double MovingAverage::next(int newNum){
    q.push(newNum);
    totalSum += newNum;
    if(q.size() > windowSize){
        // Queue is too big; need to pop
        int temp = q.front();
        q.pop();
        totalSum -= temp;
    }
    return (double)totalSum/q.size();
}

int main(){
    MovingAverage m(3);
    cout << m.next(1) << endl;
    cout << m.next(10) << endl;
    cout << m.next(3) << endl;
    cout << m.next(5) << endl;
}
