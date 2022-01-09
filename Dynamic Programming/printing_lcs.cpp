#include <bits/stdc++.h>
using namespace std;

string lcs(string &a, string &b, int n, int m)
{

    // Firstly, fill up the table
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

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
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Once the table is filled, travel in backward direction from nth - mth cell in the path of maximum number.

    string ans = "";

    int i = n, j = m;

    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            ans += a[i - 1];
            --i, --j;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
                --i;
            else
                --j;
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    // We have to print the longest common subsequence

    string a, b;
    cin >> a >> b;
    int n = a.length(), m = b.length();

    cout << lcs(a, b, n, m) << endl;

    return 0;
}