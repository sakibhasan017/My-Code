#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int M=1e9+7;
const int N=2e5+7;

struct Node {
    int data;
    Node* next,*previous;
};

void print(Node* i) {
    Node* curr = i;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->previous;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
            newNode->previous = NULL;
        } else {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
    }

    print(tail);

    return 0;
}
