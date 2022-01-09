#include <bits/stdc++.h>
using namespace std;

int main()
{
    // The recursive + memoized solution of longest  common substring requires a 3D array that is harsh on memory
    // So for this problem Top Down approach is much better

    string a, b;
    cin >> a >> b;

    int n = a.length();
    int m = b.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    int max_len = 0;

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else
            {
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = 0;
            }

            max_len = max(max_len, dp[i][j]);
        }
    }

    cout << max_len << endl;
    return 0;
}