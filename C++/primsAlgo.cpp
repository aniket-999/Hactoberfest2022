// #include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

void add_edge(int u, int v, int wt, vector<pair<int, int> > adj[] ) {
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
}

int prims(vector<pair<int, int> > adj[], int n, int src) {
    vector<int> key(n, INT_MAX);
    vector<bool> mst(n, false);
    vector<int> parent(n, -1);
    for(int i=0; i<n; i++) {
        if(i==0) key[i] = 0; 
        mst[i] = true;
        for(auto it : adj[i]) {
            if(key[it.first] > it.second) {
                key[it.first] = it.second;
                parent[it.first] = i;
            }
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        ans += key[i];
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int edge;
    cin >> edge;
    vector<pair<int, int> > adj[n+1];    // {node, weight}
    for(int i=0; i<edge; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        add_edge(u, v, wt, adj);
    }
    cout << prims(adj, n, 0) << "\n";
    return 0;
}