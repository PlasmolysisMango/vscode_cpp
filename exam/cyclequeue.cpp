#include <iostream>
#include <vector>

using namespace std;

class CQueue {
    size_t front, rear;
    size_t capacity;
    vector<int> data;
public:
    CQueue(size_t _capacity = 10): front(0), rear(0), capacity(_capacity), data(vector<int>(capacity, 0)) {}
    bool empty() const {
        if (rear == front)
            return true;
        else
            return false;
    }

    bool full() const {
        if ((rear+1)%capacity == front)
            return true;
        else
            return false;
    }

    void push(const int val) {
        if (!full()) {
            rear = (rear + 1) % capacity;
            data[rear] = val;
        }
    }

    int get_front() const {
        return data[(front+1)%capacity];
    }

    void pop() {
        if (!empty()) {
            front = (front + 1) % capacity;
        }
    }

    size_t size() const {
        return rear - front;
    }
};

int main() 
{
    CQueue q;
    q.push(5);
    q.push(4);
    q.pop();
    q.push(3);
    while (!q.empty()) {
        cout << q.get_front() << " ";
        q.pop();
    }
}