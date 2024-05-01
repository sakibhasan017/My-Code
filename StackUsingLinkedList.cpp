
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;

struct Node{
  Node *previous,*next;
  int data;
};

class stackUL{
  public:
   Node *head=NULL;
   Node *tail=NULL;
   
   int size;
    
   void push(int n){
      Node *newNode=new Node;
      newNode->data=n;
      newNode->next=NULL;
      if (head == NULL) {
            head = newNode;
            tail = newNode;
            newNode->previous = NULL;
        } else {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
        size++;
   }

   void pop(){
    tail=tail->previous;
    tail->next=NULL;
    size--;
   }

   void printForward(){
      Node *i;
      for(i=head;i !=  NULL;i=i->next){
        cout<<i->data<<" ";
      }
      cout<<endl;
   }

    void printBackward(){
      Node *i;
      for(i=tail;i !=  NULL;i=i->previous){
        cout<<i->data<<" ";
      }
      cout<<endl;
   }

   void top(){
    cout<<tail->data<<endl;
   }

   void length(){
    cout<<size<<endl;
   }


};

int main() {
    fast;
    stackUL st;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
     cin>>x;
     st.push(x);
    }

    st.printForward();
    st.printBackward();
    st.pop();
    st.pop();

    st.printForward();
    st.top();
    st.length();
  
}
