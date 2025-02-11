#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;

int parent[M+1];
int raank[M+1];


int find(int u){
   if(parent[u]==u) return u;
   else find(parent[u]);
}

void unnion(int u,int v){
  if(raank[u]==raank[v]){
    parent[v]=u;
    raank[u]++;
  }else if(raank[u] > raank[v]){
   parent[v]=u;
  }else{
    parent[u]=v;
  }
}

int main(){
    
    freopen("input.txt","r",stdin);
    
    for(int i=0;i<M;i++){
       parent[i]=i;
       raank[i]=0;
    }

    int ne;
    cin>>ne;
    bool found=false;
    for(int i=0;i<ne;i++){
      int u,v;
      cin>>u>>v;
      int root_u=find(u);
      int root_v=find(v);

      if(root_u==root_v) {
        cout<<"G contain Cycle"<<endl;
        found=true;
      }
      else unnion(root_u, root_v);
    }
   
   if(!found) cout<<"No cycle detect"<<endl;

   for(int i=1;i<=ne;i++){
      cout<<i<<" "<<parent[i]<<endl;
   }
   
}

/*
8
1 5
2 6
5 2 
7 8
6 7
9 10
9 8
10 8
*/

