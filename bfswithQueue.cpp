#include <bits/stdc++.h>
using namespace std;
const int M=10004;

vector<int> adj[M];
int vis[M];
int level[M];
int parent[M];
int main() {
   
  memset(vis,0,sizeof(vis));
  memset(parent,-1,sizeof(parent));
  memset(level,0,sizeof(level));
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
  int u,v;
  cin>>u>>v;
  adj[u].push_back(v);
  adj[v].push_back(u);
  }
  int source;
  cin>>source;
  queue<int> q;
  q.push(source);
  vis[source]=1;
  bool hasCycle=false;
  while(!q.empty()){
    int u=q.front();
    
    cout<<u<<" ";
    q.pop();
    int l=adj[u].size();

    for(int i=0;i<l;i++){
      int v=adj[u][i];
      if(vis[v] == 0){
        level[v]=level[u]+1;
        parent[v]=u;
        vis[v]=1;
        q.push(v);
      }else if(parent[u] !=v){
        hasCycle=true;
      }
    }

  }
  cout<<endl;
  for(int i=0;i<M;i++){
    for(int j=0;j<M;j++){
   if(vis[j]==1 && level[j]==i){
    cout<<"Level of "<<j<<" : "<<i<<endl;
   }
    }
  }

  if(hasCycle) cout<<"There is a Cycle"<<endl;
  else cout<<"There is no Cycle"<<endl;

}