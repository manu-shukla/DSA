#include <bits/stdc++.h>
using namespace std;

int lcs(string &a, string &b, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 || m == 0)
        return 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    // if current characters are equal, then they must be in the common subsequence
    // We then proceed with the next characters of the both the strings

    if (a[n - 1] == b[m - 1])
        return dp[n][m] = 1 + lcs(a, b, n - 1, m - 1, dp);

    // If the current characters of the strings are not equal then we have two choices
    // 1. Take one string upto n length and other upto m-1 length
    // 2. Take one string upto m length and other upto n-1 length
    // And find the maximize of these two choices because we need to find the LONGEST common subsequence length

    return dp[n][m] = max(lcs(a, b, n, m - 1, dp), lcs(a, b, n - 1, m, dp));
}

int main()
{
    // Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

    string a, b;
    cin >> a >> b;
    int n = a.length(), m = b.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    cout << lcs(a, b, n, m, dp) << endl;

    return 0;
}