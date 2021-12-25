#include <bits/stdc++.h>
using namespace std;

int bellmanFord(int src, int dest, vector<vector<int>> &edges, int n)
{

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    //This algorithm can be proved that we can find the shortest path with atmost n-1 iterations.
    for (int count = 1; count <= n - 1; ++count)
    {
        for (int i = 0; i < edges.size(); ++i)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    // This Algorithm can also be used to detect negative weight cycle.

    // To detect negative weight cycle, we can do the minimization for n-1 iteration. Again we do the minimization for nth iteration and if the distance gets minimized in the nth iteration then we can say that the graph has negative weight cycle.

    return dist[dest];
}

int main()
{
    int n, m;
    cin >> n >> m;
    //Bellman Ford Algorithm works for negative weights and can be used to detect negative weight cycles.
    vector<vector<int>> edges;

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edges.push_back({u, v, w});
    }

    int queries;
    cin >> queries;
    while (queries)
    {
        int src, dest;
        cin >> src >> dest; //Shortest Path between Src(Source) and Dest(Destination)

        int dist = bellmanFord(src, dest, edges, n);
        cout << dist << endl; // Shortest distance between src and dest.
    }

    return 0;
}