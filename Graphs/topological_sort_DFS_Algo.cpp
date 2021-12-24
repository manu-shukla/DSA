#include <bits/stdc++.h>
using namespace std;

void dfsTopoSort(vector<vector<int>> &adj, int node, vector<int> &arr, vector<bool> &visited)
{
    visited[node] = true;

    
    for (auto child : adj[node])
        if (visited[child] == false)
            dfsTopoSort(adj, child, arr, visited);


    arr.push_back(node);
}

int main()
{
    // Works for DAG
    // This is the DFS method to find the Topological Sort of a Directed Acyclic Graph(DAG)
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        --u, --v; // To make 1-based nodes to 0-based nodes

        adj[u].push_back(v);
    }
    vector<int> topoSorted;
    vector<bool> visited(n, false);


    for (int i = 0; i < n; ++i)
        if (visited[i] == false)
            dfsTopoSort(adj, i, topoSorted, visited);


    reverse(topoSorted.begin(), topoSorted.end());


    for (auto node : topoSorted)
        cout << node + 1 << " ";
    cout << endl;

    return 0;
}