#include <bits/stdc++.h>
using namespace std;

const int M = 10000;
vector<int> a[M + 1];
int vis[M + 1];


int main(){
    int ne;
    cin >> ne;
    int u, v;

    for (int i = 0; i < ne; i++) {
        cin >> u >> v;
        a[u].push_back(v); 
        a[v].push_back(u);
    }

    bool found = false;

    for(int i = 1; i <= M; i++){
        if(!a[i].empty() && !vis[i]){
            stack<pair<int, int>> st; 
            st.push({i, INT_MIN});
            vis[i] = 1;

            while(!st.empty()){
                int u = st.top().first;
                int par = st.top().second;
                st.pop();

                for(int j = 0; j < a[u].size(); j++){
                    int v = a[u][j];
                    if(!vis[v]){ 
                        vis[v] = 1;
                        st.push({v, u});
                    } else if(v != par){ 
                        found = true;
                        break;
                    }
                }
                if(found) break;
            }
        }
        if(found) break;
    }

    if(found){
        cout << "There is a cycle" << endl;
    } else {
        cout << "No cycle" << endl;
    }
    return 0;
}
