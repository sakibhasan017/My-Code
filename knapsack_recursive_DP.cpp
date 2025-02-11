#include<bits/stdc++.h>
using namespace std;

int table[1004][1004];
int weight[1004],price[1004];

int KC(int n,int wc){
 if(table[n][wc] != -1){
   return table[n][wc];
 }

 if(weight[n] > wc){
   table[n][wc]=KC(n-1,wc);
 }else{
  int in= price[n]+KC(n-1,wc-weight[n]);
  int ex=KC(n-1,wc);
  table[n][wc]=max(in,ex);
 }

 return table[n][wc];
}

int main()
{
    int n,wc;
    cin>>n>>wc;

    for(int i=1;i<=n;i++){
      for(int j=0;j<=wc;j++){
       if(i==0 || j==0) table[i][j]=0;
       else table[i][j]=-1;
      }
    }

    for(int i=1;i<=n;i++){
      cin>>weight[i]>>price[i];
    }
    
   int ans=KC(n,wc);

   cout<<ans<<endl;
    
} 
