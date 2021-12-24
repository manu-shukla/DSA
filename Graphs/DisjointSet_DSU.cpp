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

    u = findParent(u, parent);
    v = findParent(v, parent);

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
    // Disjoint Set Union or Union Find Data Structure
    // Implementing DSU by RANK and PATH COMPRESSION

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parent(n), rank(n, 0);

    for (int i = 0; i < n; ++i)
        parent[i] = i; // Every Node has its parent as itself

    int queries;
    cin >> queries;
    while (queries--)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        unionNodes(u, v, rank, parent);
    }

    // To check for example if node 2 and node 3 belong to the same component then

    if (parent[2] == parent[3])
        cout << "They belong to the same component" << endl;
    else
        cout << "They DONOT belong to the same component" << endl;

    return 0;
}