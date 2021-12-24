#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; // n Nodes and m undirected Edges
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

    vector<bool> inMST(n, false);

    vector<int> key(n, INT_MAX); //contains the minimum edge wait connected to i-th node


    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push({0, 0});
    key[0] = 0;
    while (!q.empty())
    {
        int w = q.top().first, node = q.top().second;
        q.pop();

        inMST[node] = true;

        for (auto child : adj[node])
        {
            if (inMST[child.first] == false && key[child.first] > child.second)
            {
                key[child.first] = child.second;
                q.push({child.second, child.first});
            }
        }
    }
    int c = 0;
    for (auto k : key)
    {
        c += k;
    }
    cout << endl;

    return 0;
}