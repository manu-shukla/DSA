#include <bits/stdc++.h>
using namespace std;

int up[200001][25];
int depth[200001];
vector<vector<int>> adj;

void binary_lifiting(int node, int parent, int d)
{
    depth[node] = d;
    up[node][0] = parent;

    for (int i = 1; i < 25; ++i)
    {
        if (up[node][i - 1] != -1)
        {
            up[node][i] = up[up[node][i - 1]][i - 1];
        }
        else
            up[node][i] = -1;
    }

    for (auto child : adj[node])
    {
        binary_lifiting(child, node, d + 1);
    }
}

int query(int u, int v)
{

    // We first try to bring both the nodes u & v to the same level.
    // Here we want u node to be the deeper one
    if (depth[u] < depth[v])
        swap(u, v);

    int k = depth[u] - depth[v]; // We calculate the difference in the depth
    // And now we lift up the deeper node to the same level as that of v
    for (int i = 24; i >= 0; --i)
    {
        if (k >= (1 << i))
        {
            u = up[u][i];
            k -= (1 << i);
        }
    }

    if (u == v) // is v is ancestor of u then u==v in this case
        return u;


       // Else now we together lift both u and v to their ancestors such that both their ancestors are not equal 

    for (int i = 24; i >= 0; --i)
    {
        if (up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
        }
    }

    //Now we will be at a point where the ancestor of both the nodes will be their LCA
    return up[u][0];
}

int main()
{

    // Direct Problem Link - https://www.spoj.com/problems/LCASQ/
    int n;
    cin >> n;
    adj = vector<vector<int>>(n);

    for (int i = 0; i < n; ++i)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j)
        {
            int v;
            cin >> v;
            adj[i].push_back(v);
        }
    }

    binary_lifiting(0, -1, 0);

    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << query(u, v) << endl;
    }

    return 0;
}