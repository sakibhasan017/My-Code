#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;

template<typename T>
class demoQ {
    T *Q;
    int size;
    int front, rear;

public:
    demoQ(int N){
      size=N;
      front=rear=-1;
        Q = new T[size];
    }

    void enqueue(T N) {
        if ((rear + 1) % size == front) {
            cout << "Queue is full" << endl;
        } else if (rear == -1 && front == -1) {
            front = 0;
            rear = 0;
            Q[rear] = N;
        } else {
            rear = (rear + 1) % size;
            Q[rear] = N;
        }
    }

    void deQueue() {
        if (front == -1 && rear == -1) {
            cout << "Queue is Empty" << endl;
        } else if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void print() {
    if (front == -1 && rear == -1) {
        cout << "Queue is Empty" << endl;
        return;
    }
    int i = front;
    do {
        cout << Q[i] << " ";
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);
    cout << endl;
}

    T infront() {
        return Q[front];
    }

    T back() {
        return Q[rear];
    }

    int length() {
        if (front == -1 && rear == -1)
            return 0;
        if (front <= rear)
            return rear - front + 1;
        return size - front + rear + 1;
    }
};

int main() {
    fast;
    int n;
    cin >> n;
    demoQ<int> Queue(n);
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        Queue.enqueue(x);
    }
    Queue.print();
    Queue.deQueue();
    Queue.print();
    Queue.deQueue();
    Queue.print();
    Queue.enqueue(30);
    Queue.print();
    cout << "Front: " << Queue.infront() << endl;
    cout << "Back: " << Queue.back() << endl;
    cout << "Length: " << Queue.length() << endl;
    Queue.enqueue(47);
    Queue.enqueue(87);
    Queue.print();

    return 0;
}
