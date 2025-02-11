#include<bits/stdc++.h>
#define inf (1<<30)-1;
using namespace std;

struct Compare{
    bool operator()(pair<char,int>a, pair<char,int> b){
      return a.second>b.second;
    }
};

int main(){
    
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    int cnt=0;
    char root;
    vector< pair<char,int> > adj[123];
    for(int i=0;i<n;i++){
        char u,v;
        int w;
        cin>>u>>v>>w;
      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
      if(cnt==0){
        root=u;
        cnt++;
      }
    }

    bool mst[123];
    for(int i=0;i<123;i++) mst[i]=0;

    int weights[123];
    for(int i=0;i<123;i++) weights[i]=inf;

    priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> q;
    
    weights[root]=0;

    q.push({root,0});
     
     int total=0;
    while(!q.empty()){
        char u=q.top().first;
       
        q.pop();
        if(mst[u]==1) continue;
         
         mst[u]=1;
         total+=(weights[u]);

         for(int i=0;i<adj[u].size();i++){
            char v=adj[u][i].first;
            int w=adj[u][i].second;

            if(mst[v]==0 && w<weights[v]){
                q.push({v,w});
                weights[v]=w;
            }
         }
    }
    cout<<total<<endl;
    
}

/*
14
a b 4
a h 8
b h 11
b c 8
h i 7
h g 1
c d 7
c f 4
c i 2
i g 6
g f 2
d e 9
d f 14
f e 10
*/