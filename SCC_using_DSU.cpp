#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 5;

int parent[M];
int raank[M];
bool visited[M];

int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]); 
}

void unnion(int u, int v) {
    
    if (raank[u] == raank[v]) {
        parent[v] = u;
        raank[u]++;
    } else if (raank[u] > raank[v]) {
        parent[v] = u;
    } else {
        parent[u] =v;
    }
  
}

void printCycle(int start, vector<pair<int, int>> &edges) {
    set<int> cycle_nodes;
    for (auto [u, v] : edges) {
        if (find(u) == find(v)) {
            if (!visited[u]) cycle_nodes.insert(u);
            if (!visited[v]) cycle_nodes.insert(v);
        }
    }

    if (!cycle_nodes.empty()) {
        cout << "Component: {";
        for (auto it = cycle_nodes.begin(); it != cycle_nodes.end(); ++it) {
            if (it != cycle_nodes.begin()) cout << ", ";
            cout << *it;
        }
        cout << "}" << endl;

        for (int node : cycle_nodes) visited[node] = true;
    }
}

int main() {
    for (int i = 0; i < M; i++) {
        parent[i] = i;
        raank[i] = 0;
        visited[i] = false;
    }

    int ne;
    cin >> ne;

    vector<pair<int, int>> edges;
    set<int> nodes;

    for (int i = 0; i < ne; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u,v});
        nodes.insert(u);
        nodes.insert(v);

        int root_u = find(u);
        int root_v = find(v);
        
        if (root_u==root_v) {
            printCycle(u, edges); 
            edges.clear();       
        }else{
            unnion(root_u,root_v);

        }
    }

    for (int node : nodes) {
        if (!visited[node]) {
            cout << "Component: {" << node << "}" << endl;
        }
    }

    return 0;
}
