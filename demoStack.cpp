#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int M=1e9+7;
const int N=2e5+7;

template <typename T> class demoStack{
  
  int size=0;
  int maxSize=0;
  T *a; 

public:
  demoStack(){ 
    a = new T[maxSize];
  }

  demoStack(T n){ 
    maxSize=n;
    a = new T[maxSize];
  }

  void push(T n){
    a[size]=n;
    size++;
  }
   
  T pop(){ 
    T temp=a[size-1]; 
    size--;
    return temp;
  }

  void print(){
    for(int j=0;j<size;j++){
     cout<<a[j]<<" ";
    }
    cout<<endl;
  }

  T top(){
    return a[size - 1];
  }
   
  bool is_Empty(){ 
    return size == 0;
  }

  
};

int main() {
   int n;
   cin>>n;
   demoStack<int> st(n);
   int x;

   cout<<st.is_Empty()<<endl;

   for(int i=0;i<n;i++){
    cin>>x;
    st.push(x);
   }

   st.print();
   cout<<st.top()<<endl;
   st.pop();
   st.pop();
   st.print();
   
}
