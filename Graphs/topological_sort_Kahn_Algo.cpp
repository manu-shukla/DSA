#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Works for DAG
    // This is the BFS method to find the Topological Sort of a Directed Acyclic Graph(DAG)

    // This Algorithm is called Kahn's Algorithm (BFS Based)

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

    vector<int> inDeg(n, 0); // InDegree of the node

    for (int node = 0; node < n; ++node)
    {
        for (auto child : adj[node])
        {
            ++inDeg[child];
        }
    }

    queue<int> q;

    // Pushing All Nodes with zero Indegree
    for (int i = 0; i < inDeg.size(); ++i)
        if (inDeg[i] == 0)
            q.push(i);

    vector<int> topoSorted;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topoSorted.push_back(node);

        for (auto child : adj[node])
        {
            --inDeg[child]; // Removing the edge from node to child thereby decreasing the indegree
            if (inDeg[child] == 0)
                q.push(child);
        }
    }

    for (auto node : topoSorted)
        cout << node + 1 << " ";
    cout << endl;

    return 0;
}