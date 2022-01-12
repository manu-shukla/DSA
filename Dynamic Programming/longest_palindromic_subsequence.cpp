#include <bits/stdc++.h>
using namespace std;

int lcs(string &a, string &b, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 || m == 0)
        return 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    if (a[n - 1] == b[m - 1])
        return dp[n][m] = 1 + lcs(a, b, n - 1, m - 1, dp);

    return dp[n][m] = max(lcs(a, b, n - 1, m, dp), lcs(a, b, n, m - 1, dp));
}

int main()
{

    // In longest palindromic subsequence, the answer is simply the lcs of the string and its reverse string.

    string a;
    cin >> a;

    int n = a.length();
    string b = a;
    reverse(b.begin(), b.end());

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    cout << lcs(a, b, n, n, dp) << endl;

    return 0;
}