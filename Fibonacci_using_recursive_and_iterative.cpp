#include<bits/stdc++.h>
using namespace std;

int recursive_table[200007]={-1};

int recursive_way(int n){
    if(recursive_table[n] != -1) return recursive_table[n];

    return recursive_table[n]=recursive_way(n-1)+recursive_way(n-2);
}

int main(){
    
    int iterative_table[200007]={-1};

    iterative_table[0]=recursive_table[0]=0;
    iterative_table[1]=recursive_table[1]=1;

    for(int i=2;i<=200005;i++){
      iterative_table[i]=iterative_table[i-1]+iterative_table[i-2];
    }


    int n;
    cin>>n;
     
    int ans=recursive_way(n); 

    cout<<"Iterative Result: "<<iterative_table[n]<<endl;
    cout<<"Recursive Result: "<<ans<<endl;

}