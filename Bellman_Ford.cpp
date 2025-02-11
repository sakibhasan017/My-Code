#include <bits/stdc++.h>
using namespace std;

int main() {
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  
    int edge; 
    cin >> edge;

    vector<tuple<char, char, int>> edges;
    set<char> st;
    for (int i = 0; i < edge; i++) {
        char u, v;
        int w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        st.insert(u);
        st.insert(v);
        
    }

    char source; 
    cin >> source;
    int n=st.size();

    vector<int> dist(123, INT_MAX); 
    dist[source] = 0; 

    
    for (int i = 0; i <=n - 1; i++) {
     
        for (auto edge : edges) {
            int u = get<0>(edge);
            int v = get<1>(edge);
            int w = get<2>(edge);
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            
            }
        }
        
    }
    
   
    for (char t: st) {
        
            cout << dist[t] << " ";
        
    }
    cout << endl;

    return 0;
}

/*
9
A B 6
A C 4
A D 5
C B -2
B E -1
E F 3
D F -1
D C -2
C E 3
A
*/