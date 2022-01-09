#include <bits/stdc++.h>
using namespace std;

int lcs(string &a, string &b, int n, int m)
{

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
                    // if current characters are equal, then they must be in the common subsequence
                    // We then proceed with the next characters of the both the strings
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else
                    // If the current characters of the strings are not equal then we have two choices
                    // 1. Take one string upto n length and other upto m-1 length
                    // 2. Take one string upto m length and other upto n-1 length
                    // And find the maximize of these two choices because we need to find the LONGEST common subsequence length
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main()
{
    // Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

    string a, b;
    cin >> a >> b;
    int n = a.length(), m = b.length();

    cout << lcs(a, b, n, m) << endl;

    return 0;
}