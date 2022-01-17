#include <bits/stdc++.h>
using namespace std;

int solve(int e, int f, vector<vector<int>> &dp)
{
    if (e == 1 || f <= 1)
        return f;
    // If we have only one egg left then we have to check all the floors from 1 to f.
    // If the number of floors is 0, then we do not need to check any floor and return 0
    // If the number of floors is 1, then we need to check only that floor and thus we return 1.
    if (dp[e][f] != -1)
        return dp[e][f];

    int ans = INT_MAX;

    // Binary Search
    int l = 1, r = f;
    while (l <= f)
    {
        int mid = l + (r - l) / 2;

        int breaked = solve(e - 1, mid - 1, dp); // If egg is breaked, then we check for 1 egg less and below the current floor

        int notbreaked = solve(e, f - mid, dp); // If the egg is not broken then we check with same number of eggs and above that floor meaning the number of floor that are left to be checked is Current total floors - current floor we have checked and egg did not break

        ans = min(ans, 1 + max(breaked, notbreaked));

        if (breaked < notbreaked)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return dp[e][f] = ans;
}

int main()
{
    int eggs, floors;
    cin >> eggs >> floors;

    vector<vector<int>> dp(eggs + 1, vector<int>(floors + 1, -1));

    cout << solve(eggs, floors, dp) << endl;

    return 0;
}