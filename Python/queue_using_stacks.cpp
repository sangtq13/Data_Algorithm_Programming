#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
class Queue {
public:
    Queue(){}
    void Enqueue(int data) {
        s1.push(data);
    }
    
    void Dequeue() {
        if (s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }
    
    int Front() {
        if (s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    } 
private:
    stack<int> s1;
    stack<int> s2;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    Queue q;
    int qr;
    int command;
    cin >> qr;
    for (int i = 0; i < qr; ++i) {
        cin >> command;
        if (command == 1) {
            int num;
            cin >> num;
            q.Enqueue(num);
        }
        else if (command == 2) {
            q.Dequeue();
        }
        else if (command == 3) {
            cout << q.Front() << endl;
        }
    }
    
    return 0;
}
