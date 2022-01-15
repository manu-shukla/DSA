#include <bits/stdc++.h>
using namespace std;

bool isPalin(string &s, int l, int r)
{
    // Palindrome checking function

    if (l > r)
        return false;

    while (l < r)
    {
        if (s[l++] != s[r--])
            return false;
    }

    return true;
}

int partitions(string &s, int i, int j, vector<vector<int>> &dp)
{
    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (isPalin(s, i, j))
        return 0;

    int ans = INT_MAX;

    for (int k = i; k < j; ++k)
    {
        // One is added because we have made a partition from of string into two strings (i->k) | (k+1 -> j)

        int curr_ans = 1 + partitions(s, i, k, dp) + partitions(s, k + 1, j, dp);

        ans = min(ans, curr_ans);
    }

    return dp[i][j] = ans;
}

int main()
{
    /*
        Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of given string.

    Baiscally, we need to divide the string into segments such that all the segments of the string are palindrome. Also, we need to find the minimum number of dividers required to achieve the above task.

 */

    // This problem uses the concept of matrix chain multiplication

    string s;
    cin >> s;

    int n = s.length();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << partitions(s, 0, n - 1, dp) << endl;

    return 0;
}