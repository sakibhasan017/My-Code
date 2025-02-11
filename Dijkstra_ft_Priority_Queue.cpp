#include<bits/stdc++.h>
using namespace std;

struct Compare{
    bool operator()(pair<int,int>a, pair<int,int> b){
      return a.second>b.second;
    }
};


int main(){
 
  priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> q;
 
  int edge;
  cin>>edge;
  int M=1e9+7;
  vector<pair<int,int> > adj[M+1];
  
  set<int> s;
  for(int i=0;i<edge;i++){
    int u,v,w;
    cin>>u>>v>>w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
    s.insert(u);
    s.insert(v);
  }

  int source,dest;
  cin>>source>>dest;

  vector<int> arr(M+1, INT_MAX);
    arr[source] = 0;
    
    q.push({source,0});


    while(!q.empty()){
        int node=q.top().first;
        int weight=q.top().second;
        
        q.pop();
        
        if(arr[node]<weight) {
      continue;
      }
    for(int i=0;i<adj[node].size();i++){
      int v=adj[node][i].first;
      int w=adj[node][i].second;
     if(arr[node]+w< arr[v]){
       arr[v]=arr[node]+w;
       q.push({v,arr[v]});
     }
    
    }
    
    } 
  
  for(auto x: s){
  cout<<arr[x]<<" ";
 }

}