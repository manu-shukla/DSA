#include <bits/stdc++.h>
using namespace std;

int up[200001][25]; // Stores ith node 2^j th upward ancestor
vector<vector<int>> adj;
void binaryLifiting(int node, int parent)
{
    up[node][0] = parent; // 2^0 = 1 th upward ancestor of node is parent itself

    for (int i = 1; i < 25; ++i)
    {
        if (up[node][i - 1] != -1)
        {
            up[node][i] = up[up[node][i - 1]][i - 1];
            // 2^i = 2^(i-1) + 2^(i-1)
            //  So going to nodes 2^(i-1) parent and checking there its 2^(i-1) parent
        }
        else
            up[node][i] = -1;
    }

    for (auto child : adj[node])
    {
        if (child != parent)
        {
            binaryLifiting(child, node);
        }
    }
}
int query(int node, int k)
{
    // where node is current Node and k is the kth ancestor of current node

    if (node == -1 || k == 0)
        return node;

    for (int i = 24; i >= 0; --i)
    {
        if (k >= (1 << i))
        {
            return query(up[node][i], k - (1 << i));
        }
    }
    return -1;
}

int main()
{

    int n, q; // n - No. of Nodes | m - No. of edges
    cin >> n >> q;

    adj = vector<vector<int>>(n + 1);

    for (int i = 0; i < n - 1; ++i)
    {
        int x;
        cin >> x;

        adj[x].push_back(i + 2);
        adj[i + 2].push_back(x);
    }

    binaryLifiting(1, -1);

    while(q--)
    {
        int node, k;
        cin >> node >> k;

        cout << query(node, k)<< endl;
    }

    return 0;
}