#include<bits/stdc++.h>
#define inf (1<<30)-1;
using namespace std;


int main(){
    
    freopen("input.txt","r",stdin);
    
    int G[26][26];
    for(int i=0;i<26;i++){
      for(int j=0;j<26;j++){
      if(i==j) G[i][j]=0;
      G[i][j]=inf;
    }
    }

    int ne;
    cin>>ne;

    map<char,int> m;
    int id=0;

    for(int i=0;i<ne;i++){
      char u,v;
      int w;
      cin>>u>>v>>w;

    if(m.find(u)==m.end()){
       m[u]=id;
       id++;
     }

     if(m.find(v)==m.end()){
       m[v]=id;
       id++;
     }
     G[m[u]][m[v]]=w;
    }

for(int i=0;i<id;i++){
      for(int j=0;j<id;j++){
        for(int k=0;k<id;k++){
         if(G[j][i]+G[i][k]<G[j][k]){
           G[j][k]=G[j][i]+G[i][k];
         }
        }
      }
    }

    for(int i=0;i<id;i++){
     for(int j=0;j<id;j++){
      cout<<G[i][j]<<" ";
     }
     cout<<endl;
    }

}

/*
10
A B 4
C A 2
A D 5
E A 1
B E 6
D E 2
E D 4
C D 3
D C 1
B C 1
*/