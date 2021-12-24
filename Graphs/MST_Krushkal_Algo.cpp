#include <bits/stdc++.h>
using namespace std;

int findParent(int node, vector<int> &parent)
{
    if (parent[node] == node)
        return node;

    return parent[node] = findParent(parent[node], parent); // Path Compression
}
void unionNodes(int u, int v, vector<int> &rank, vector<int> &parent)
{

    if (rank[u] > rank[v])
        parent[v] = u;

    else if (rank[v] > rank[u])
        parent[u] = v;

    else
    {
        ++rank[u];
        parent[v] = u;
    }
}

int main()
{
    // Krushkal's Algorithm is used to find the MST
    // It uses DSU Data Structure in its algorithm
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> parent(n), rank(n, 0);

    for (int i = 0; i < n; ++i)
        parent[i] = i; // Every Node has its parent as itself

    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < n; ++i)
    {
        for (auto child : adj[i])
        {
            edges.push_back({child.second, {i, child.first}});
        }
    }
    sort(edges.begin(), edges.end()); // Sorting helps us to select the minimum weight first thereby allowing us to form Minimum Spanning Tree

    int cost = 0;

    for (int i = 0; i < edges.size(); ++i)
    {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int w = edges[i].first;
        u = findParent(u, parent);
        v = findParent(v, parent);
        // If u==v, this means that they belong to the same component i.e. they are in the MST
        if (u != v)
        {
            // It is not is MST currently
            cost += w;
            unionNodes(u, v, rank, parent); // Including the nodes in the MST
        }
    }

    cout << "Total weights in the MST: " << cost << endl;

    return 0;
}