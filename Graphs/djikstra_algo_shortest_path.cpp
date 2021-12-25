#include <bits/stdc++.h>
using namespace std;

int djikstra(int src, int dest, vector<vector<pair<int, int>>> &adj)
{
    int n = adj.size();
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min Heap
    pq.push({0, src});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for (auto child : adj[node])
        {
            if (d + child.second < dist[child.first])
            {
                // Minimizing the distance from source to child

                dist[child.first] = d + child.second;

                pq.push({dist[child.first], child.first});
            }
        }
    }

    return dist[dest];
}

int main()
{

    int n, m;
    cin >> n >> m;
    // Works for both directed and undirected graphs
    // Doesn't work for negative weights

    vector<vector<pair<int, int>>> adj(n);
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v; // Making 1-based nodes to 0-based nodes
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int queries;
    cin >> queries;
    while (queries)
    {
        int src, dest;
        cin >> src >> dest; //Shortest Path between Src(Source) and Dest(Destination)

        int dist = djikstra(src, dest, adj);
        cout << dist << endl; // Shortest distance between src and dest.
    }

    return 0;
}