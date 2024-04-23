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
    string p = "";
  for(int i = 0; i < q.length(); i++) {
        if(q[i] == '(') {
            Basket.push(q[i]);
        } else if(q[i] == ')') {
            while(Basket.top() != '(') {
                p += Basket.top();
                Basket.pop();
            }
            Basket.pop();
        }else if (q[i] == '+' || q[i] == '-' || q[i] == '/' || q[i] == '*' || q[i]=='^') {
    while (!Basket.empty() && prec(q[i]) < prec(Basket.top()) ||
                   !Basket.empty() && prec(q[i]) == prec(Basket.top())
                  ) {
                p += Basket.top();
                Basket.pop();
            }
            Basket.push(q[i]);
        }
    
      
else{
      p+=q[i];
      
    }
  }
  cout<<p<<endl;

}
