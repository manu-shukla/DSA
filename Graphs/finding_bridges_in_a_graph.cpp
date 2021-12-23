#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &low, vector<int> &in, int &timer)
{
    visited[node] = true;
    low[node] = in[node] = timer;
    ++timer;

    for (auto child : adj[node])
    {
        if (child == parent)
            continue;

        if (visited[child] == true)
        {
            // Edge from Node -> Child is a backward Edge.
            low[node] = min(low[node], in[child]);
        }
        else
        {
            // Edge from Node -> Child is a forward Edge.

            dfs(child, node, adj, visited, low, in, timer);

            if (low[node] < low[child])
            {
                cout << node << " -> " << child << " is a bridge" << endl;
            }
            low[node] = min(low[node], low[child]);
        }
    }
}

int main()
{

    int n, m; // n Nodes and m Edges
    cin >> n >> m;

    //Undirected Graph
    vector<vector<int>> adj(n);
    vector<bool> visited(n);
    vector<int> low(n), in(n);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int timer = 0;
    dfs(0, -1, adj, visited, low, in, timer);
}