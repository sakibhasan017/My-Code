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

/*
#include <bits/stdc++.h>
using namespace std;
const int M = 10004;

vector<int> adj[M];
bool vis[M];

bool dfs(int u, int parent) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) {
            if (dfs(v, u)) return true;
        } else if (v != parent) {
            return true;
        }
    }
    return false;
}

int main() {
    memset(vis, false, sizeof(vis));

    int n;
    cout << "Enter number of edges: ";
    cin >> n;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool hasCycle = false;

    for (int i = 1; i < M; i++) {
        if (!vis[i] && !adj[i].empty()) {
            if (dfs(i, -1)) {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle)
        cout << "There is a Cycle" << endl;
    else
        cout << "There is no Cycle" << endl;

    return 0;
}
*/
