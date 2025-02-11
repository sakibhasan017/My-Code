#include<bits/stdc++.h>
#define inf (1<<30)-1;
using namespace std;
vector<pair<int, pair <int,int> > > G;
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

bool create_cycle(int u,int v){
    int root_u=find(u);
    int root_v=find(v);
    if(root_u==root_v) return true;
    else unnion(root_u, root_v);
    return false;
}

int main(){
    
    freopen("input.txt","r",stdin);
    
     for(int i=0;i<M;i++){
       parent[i]=i;
       raank[i]=0;
    }


    int ne;
    cin>>ne;

    for(int i=0;i<ne;i++){
      int u,v,w;
      cin>>u>>v>>w;
       G.push_back({w,{u,v}});
    }

    sort(G.begin(),G.end());
    vector<pair<int,pair<int,int> > > MST;
    int mst_weight=0;

    for(int i=0;i<ne;i++){
     int w=G[i].first;
     int u=G[i].second.first;
     int v=G[i].second.second;

     if(create_cycle(u,v)) continue;

     MST.push_back({w,{u,v}});
     mst_weight+=w;

    }
    
    cout<<mst_weight<<endl;
    for(int i=0;i<MST.size();i++){
      cout<<MST[i].second.first<<" "<<MST[i].second.second<<" "<<MST[i].first<<endl;
    }
}

/*
9
5 4 9
4 3 5
2 4 3
4 1 1
2 6 7
5 6 8
3 2 3
5 1 4
1 2 2
*/