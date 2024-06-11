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
  
}
