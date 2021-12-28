#include <bits/stdc++.h>
using namespace std;

void topoSort(int node, vector<vector<int>> &adj, stack<int> &topo, vector<bool> &visited)
{

    visited[node] = true;
    for (auto child : adj[node])
        if (visited[child] == false)
            topoSort(child, adj, topo, visited);

    topo.push(node);
}
void dfs(int node, vector<vector<int>> &tra, vector<bool> &visited)
{
    visited[node] = true;
    cout << node << " ";

    for (auto child : tra[node])
        if (visited[child] == false)
            dfs(child, tra, visited);
}
int main()
{
    // Kosaraju Algorithm is used to find the strongly connected components (SCC) that are present in the graph.

    // Steps in Kosaraju Algorithm:
    // 1. Topologically sort the graph
    // 2. DFS the transposed graph in order of topological sort
    // 3. The current unvisited nodes form a SCC.

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<vector<int>> tra(n); //Transposed Graph in which edges u -> v is v->u .

    for (int i = 0; i < n; ++i)
    {
        for (auto child : adj[i])
        {
            tra[child].push_back(i);
        }
    }

    stack<int> topo;
    vector<bool> visited(n, false);

    // Finding Topology Sort of the Graph
    for (int i = 0; i < n; ++i)
        if (visited[i] == false)
            topoSort(i, adj, topo, visited);

    // Making visited array default again for DFS call
    for (int i = 0; i < n; ++i)
        visited[i] = false;

    // DFSing the nodes in the topological sorted order
    while (!topo.empty())
    {
        int node = topo.top();
        topo.pop();
        if (visited[node] == false)
        {
            cout << "COMPONENT: [ ";
            dfs(node, tra, visited);
            cout << "]";
            cout << endl;
        }
    }

    return 0;
}