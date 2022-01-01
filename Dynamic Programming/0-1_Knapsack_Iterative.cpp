#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, w;
    cin >> n >> w;

    vector<int> wt(n), val(n);
    for (int i = 0; i < n; ++i)
        cin >> wt[i];
    for (int i = 0; i < n; ++i)
        cin >> val[i];

    vector<vector<int>> dp(n + 1, vector<int>(w + 1));

    // Base Condition in Bottom Up Approach == Initialization in Top Down Approach

    for (int i = 0; i <= n; ++i)
        dp[i][0] = 0;
    for (int i = 0; i <= w; ++i)
        dp[0][i] = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= w; ++j)
        {

            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][w] << endl;
    return 0;
}