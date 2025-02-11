#include<bits/stdc++.h>
using namespace std;


   bool Compare(pair<pair<int,int>,pair<int,int> >a,pair<pair<int,int>,pair<int,int> >b){
     if(a.first.first>b.first.first) return 1;
     else if(a.first.first==b.first.first){
        if(a.first.second<b.first.second) return 1;
        else if(a.first.second==b.first.second){
            if(a.second.first<b.second.first) return 1;
            else if(a.second.first==b.second.first){
                if(a.second.second>b.second.second) return 1;
                else return 0;
            } 
             else return 0;
        }
         else return 0;
     }
     else return 0;
   }
   

int main(){
    
    freopen("input.txt","r",stdin);
    vector<pair<pair<int,int>,pair<int,int> > >v;
    int n;cin>>n;
    for(int i=0;i<n;i++){
       int x,y,z,w;
       cin>>x>>y>>z>>w;
       v.push_back({{x,y},{z,w}});
    }
    
    cout<<"Before Sorting: "<<endl;

    for(int i=0;i<n;i++){
      cout<<v[i].first.first<<" "<<v[i].first.second<<" "<<v[i].second.first<<" "<<v[i].second.second<<endl;
    }

    sort(v.begin(),v.end(),Compare);

    cout<<"\nAfter Sorting: "<<endl;

    for(int i=0;i<n;i++){
      cout<<v[i].first.first<<" "<<v[i].first.second<<" "<<v[i].second.first<<" "<<v[i].second.second<<endl;
    }


}