#include <bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>> &mat)
{
    int n = mat.size();

    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (mat[i][k] == -1 || mat[k][j] == -1)
                    continue;

                else if (mat[i][j] == -1)
                    mat[i][j] = mat[i][k] + mat[k][j];

                else
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }
}

int main()
{
    // Floyd Warshall Algorithm is used the find the shortest distance between any two nodes.
    // It works for negative weights as well.
    // Time complexity - O(n3)

    // Adjancy Matrix is used in this Algo.

    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cin >> mat[i][j];
    }

    floydWarshall(mat);

    // The matrix now has the shortest path between and two nodes;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    return 0;
}