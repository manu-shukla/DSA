// Recursive bottom-up approach with memozitation of 0-1 Knapsack Problem

#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &wt, vector<int> &val, int w, vector<vector<int>> &dp, int n)
{
    if (n == 0 || w == 0)
        return 0;

    if (dp[n][w] != -1)
        return dp[n][w];

    if (wt[n - 1] > w) // if the current weight is greater than current bag capacity then do not include the item.
        return dp[n][w] = knapsack(wt, val, w, dp, n - 1);

    // if the current weight is less than or equal to current bag capacity then we have two choices

    // 1. Either to include the item and proceed with same item again.
    // 2. Or Do not include the item and proceed next
    // We have to maximize the total values of items in bag so taking the maximum of 1 and 2.
    return dp[n][w] = max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], dp, n), knapsack(wt, val, w, dp, n - 1));
}

int main()
{

    //In this problem we need to maximize the total value of items stored in the bag.
    // In this type, we have unlimited supply of the current item, rest is same as 0-1 knapsack
    int n, w;
    cin >> n >> w;

    vector<int> wt(n), val(n);
    for (int i = 0; i < n; ++i)
        cin >> wt[i];
    for (int i = 0; i < n; ++i)
        cin >> val[i];

    vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));

    cout << knapsack(wt, val, w, dp, n) << endl;

    return 0;
}