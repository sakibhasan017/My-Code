#include<bits/stdc++.h>
using namespace std;



int main()
{
    int n,wc;
    cin>>n>>wc;

    int weight[n+1],price[n+1];

    for(int i=1;i<=n;i++){
      cin>>weight[i]>>price[i];
    }
    int table[n+1][wc+1];

    for(int i=0;i<=n;i++){
      for(int j=0;j<=wc;j++){
        if(i==0 || j==0){
          table[i][j]=0;
        }else if(weight[i]>j){
          table[i][j]=table[i-1][j];
        }else{
          int in=price[i]+table[i-1][j-weight[i]];
          int ex=table[i-1][j];
          table[i][j]=max(in,ex);
        }
      }
    }

     for(int i=0;i<=n;i++){
      for(int j=0;j<=wc;j++){
        cout<<table[i][j]<<" ";
      }
      cout<<endl;
     }
} 
