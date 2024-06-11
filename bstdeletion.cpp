#include <bits/stdc++.h>
using namespace std;

//Binary Search Tree Implementation and Inorder Traverse

struct Node{
   int data;
   Node *l,*r;

   Node(){
    l=NULL;
    r=NULL;
   }
};


void bst(Node *root,int n){
   
   if(root->data < n){
      if(root->r == NULL){
        Node *newNode=new Node;
        newNode->data=n;
        root->r=newNode;
      }else{
        bst(root->r,n);
      }
   }else{
      if(root->l == NULL){
        Node *newNode=new Node;
        newNode->data=n;
        root->l=newNode;
      }else{
        bst(root->l,n);
      }
   }
}


void printbst(Node *root){
  if(root==NULL) return;

  printbst(root->l);

  cout<<root->data<<" ";

  printbst(root->r);
}
queue<int> q;

void queueSave(Node *root) {
    if (root == NULL) return;
    q.push(root->data);
    queueSave(root->l);
    queueSave(root->r);
}

Node* findNode(Node *&root, int n) {
    if (root == NULL) return NULL;
    if (root->data == n) {
        queueSave(root);
        Node* temp = root;
        root = NULL;
        return temp;
    }
    if (n < root->data) {
        return findNode(root->l, n);
    } else {
        return findNode(root->r, n);
    }
}


int main() {
  Node *root=NULL;
  
  int n;
  cin>>n;
  int x;
  for(int i=0;i<n;i++){
    cin>>x;
    if(root==NULL){
      root =new Node;
      root->data=x;
    }else{
    bst(root,x);
    }
  }

  
   cout<<endl;
  printbst(root);
  
   int k;
   cin>>k;
  findNode(root, k);


  q.pop();
  while(!q.empty()){
     bst(root,q.front());
     q.pop();

  }
 
 cout<<endl;
  printbst(root);

  
}
