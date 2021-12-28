#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st, vector<bool> &inStack, vector<int> &in, vector<int> &low, int &timer)
{
    inStack[node] = visited[node] = true;
    in[node] = low[node] = timer++;
    st.push(node);

    for (auto child : adj[node])
    {
        if (visited[child] == true && inStack[child] == true)
        {
            low[node] = min(low[node], in[child]);
        }
        else if (visited[child] == false)
        {
            dfs(child, adj, visited, st, inStack, in, low, timer);

            if (inStack[child] == true)
                low[node] = min(low[node], low[child]);
        }
    }

    if (low[node] == in[node]) //Found a SCC after execution of all possible nodes
    {
        cout << "SCC: [ ";
        while (1)
        {
            int curr = st.top();
            st.pop();
            inStack[curr] = false;
            cout << curr + 1 << " ";
            if (curr == node)
                break;
        }
        cout << "]" << endl;
    }
}

int main()
{

    // Tarjan's Algorithm helps in finding the strongly connected components (SCC) in a graph
    // It uses the concept of in time and low time, the same being used in finding bridges and articulation point

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
    }

    vector<bool> visited(n, false), inStack(n, false);

    stack<int> st;
    vector<int> low(n), in(n);

    int timer = 1;

    for (int i = 0; i < n; ++i)
    {
        if (visited[i] == false)
            dfs(i, adj, visited, st, inStack, in, low, timer);
    }

    return 0;
}