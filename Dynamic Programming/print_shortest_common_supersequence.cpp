#include <bits/stdc++.h>
using namespace std;

int main()
{
    // In this problem, we have to print shortest common supersequence which is a string which has subsequences as string-1 and string-2.

    // This problem is very similar to printing the longest common subsequence.

    string a, b;
    cin >> a >> b;

    int n = a.length(), m = b.length();
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

    string scs = "";

    int i = n, j = m;

    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            scs += a[i - 1];
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

    // If still some of the substring of the one the string is left, we will simply add it to our scs variable.
    if (i > 0)
        while (i--)
            scs += a[i];

    else if (j > 0)
        while (j--)
            scs += b[j];

    reverse(scs.begin(), scs.end());

    cout << scs << endl;
    return 0;
}