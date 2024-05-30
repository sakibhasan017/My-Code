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
  stack<int> s;
  s.push(source);
  vis[source]=1;
  bool hasCycle=false;
  int stopwatch=0;
  int entry[M],finish[M];
  
  entry[source] = stopwatch;
            cout<<"Entry of "<<source<<": "<<entry[source]<<endl;
            stopwatch++;

  while(!s.empty()){
    int u=s.top();
    int parent=s.top();
    
    //cout<<u<<" ";
    
    int l=adj[u].size();
      


    for(int i=0;i<l;i++){
      int v=adj[u][i];
      if(vis[v] == 0){
        level[v]=level[u]+1;
        
        vis[v]=1;
        s.push(v);
         entry[v] = stopwatch;
            cout<<"Entry of "<<v<<": "<<entry[v]<<endl;
            stopwatch++;
        break;
      }
    }
    if (s.top() == u) { 
                    finish[u] = stopwatch;
                    cout<<"Finish of "<<u<<": "<<finish[u]<<endl;
                    stopwatch++;
                    s.pop();
                }

  }
  cout<<endl;
  


}