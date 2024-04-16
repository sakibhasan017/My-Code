#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int M=1e9+7;
const int N=2e5+7;

struct Node{

 Node *previous,*next;
 int data;
};

int main() {
   Node *head=new Node;
   Node *tail=new Node;
   head->previous=NULL;
   Node *Hsave=head;
   Hsave->previous=NULL;
   int n;
   cin>>n;
   for(int i=0;i<n;i++){
     int x;
     cin>>x;
     Node *newNode=new Node;
     newNode->data=x;
     newNode->previous=Hsave;
     newNode->next=NULL;
     Hsave->next=newNode;
     Hsave=newNode;

   }
   Node *i;
   for(i=Hsave;i->previous!=NULL;i=i->previous){
      cout<<i->data<<" ";
   }
   cout<<endl;

}
