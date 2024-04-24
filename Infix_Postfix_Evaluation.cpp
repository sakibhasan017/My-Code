#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int M=1e9+7;
const int N=2e5+7;


int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}


int main() {
   
  fast;
  string q;
    cin >> q;
   
    stack<char> Basket;
    Basket.push('(');
    q += ')';
    string p = "",bu="";
    int cnt=0;
  for(int i = 0; i < q.length(); i++) {
        if(q[i] == '(') {
            if(cnt>0){
            bu+=',';
            cnt=0;
         }
            Basket.push(q[i]);
        } else if(q[i] == ')') {
            if(cnt>0){
            bu+=',';
            cnt=0;
         }
            while(Basket.top() != '(') {
                p += Basket.top();
                bu+=Basket.top();
                bu+=',';
                Basket.pop();
            }
            Basket.pop();
            
        }else if (q[i] == '+' || q[i] == '-' || q[i] == '/' || q[i] == '*' || q[i]=='^') {
         if(cnt>0){
            bu+=',';
            cnt=0;
         }
    while (!Basket.empty() && prec(q[i]) < prec(Basket.top()) ||
                   !Basket.empty() && prec(q[i]) == prec(Basket.top())
                  ) {
                p += Basket.top();
                bu+=Basket.top();
                bu+=',';
                Basket.pop();
            }
            Basket.push(q[i]);
            
        }
    
      
else{
      cnt++;
      p+=q[i];
      bu+=q[i];
      
    }
  }
  cout<<p<<endl;
  cout<<bu<<endl;
  //Postfix Evaluation
   stack<int> st;
   bu+=')';
   for(int i = 0; i < bu.length(); i++){
     if(bu[i]==')'){
        break;
     }else if(bu[i] == '+' || bu[i] == '-' || bu[i] == '/' || bu[i] == '*' || bu[i]=='^'){
       if(bu[i] == '+'){
         int tempC=st.top();
         st.pop();
         int tempVC=st.top();
         st.pop();
         st.push(tempVC+tempC);
         
       }else if(bu[i] == '-'){
          int tempC=st.top();
         st.pop();
         int tempVC=st.top();
         st.pop();
         st.push(tempVC-tempC);
       }else if(bu[i] == '*'){
          int tempC=st.top();
         st.pop();
         int tempVC=st.top();
         st.pop();
         st.push(tempVC*tempC);
       }else if(bu[i] == '/'){
         int tempC=st.top();
         st.pop();
         int tempVC=st.top();
         st.pop();
         st.push(tempVC/tempC);
       }else if(bu[i] == '^'){
        int tempC=st.top();
         st.pop();
         int tempVC=st.top();
         st.pop();
         st.push(pow(tempVC,tempC));
         
       }
     }else if(bu[i]>='0' && bu[i]<='9'){
       int c=0,j=i;
       string temp="";
       while(bu[j]!=','){
        temp+=bu[j];
        c++;
        j++;
       }
       i+=c;
       st.push(stoi(temp));
     }
   }

   cout<<st.top()<<endl;

}
