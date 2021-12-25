#include <bits/stdc++.h>
using namespace std;

void dfsCutPoint(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &low, vector<int> &in, int &timer)
{
    visited[node] = true;
    in[node] = low[node] = timer;
    ++timer;
    int subTree = 0;
    for (auto child : adj[node])
    {
        if (parent == child)
            continue;

        if (visited[child] == true)
        {
            low[node] = min(low[node], in[child]);
        }
        else
        {
            dfsCutPoint(child, node, adj, visited, low, in, timer);
            if (low[child] >= in[node] && parent != -1)
            {
                cout << node + 1 << " is a cut Point" << endl;
            }
            low[node] = min(low[child], low[node]);

            ++subTree;
        }
    }
    if (parent == -1 && subTree > 1)
        cout << node + 1 << " is a cut point" << endl; //Root is also a cut point because it has more than one subtree.
}

int main()
{
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

    vector<bool> visited(n, false);
    vector<int> low(n), in(n);
    int timer = 1;
    for (int i = 0; i < n; ++i)
        if (visited[i] == false)
            dfsCutPoint(i, -1, adj, visited, low, in, timer);

    return 0;
}