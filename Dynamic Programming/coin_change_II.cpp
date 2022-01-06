#include <bits/stdc++.h>
using namespace std;

int findans(vector<int> &coins, int n, int amount, vector<vector<int>> &dp)
{
    if (amount == 0)
        return 1;
    if (n == 0)
        return 0;

    if (dp[n][amount] != -1)
        return dp[n][amount];

    // If coins is greater than the current amount then do not include this coin and proceed to next coin.

    if (coins[n - 1] > amount)
        return dp[n][amount] = findans(coins, n - 1, amount, dp);

    // We have to find the total numbers of ways of two cases of either selecting the coin and proceed with solving again for the same set of coins

    // or not select the current coin and proceed with solving the next set of coins i.e. excluding upto current coins from the last.

    // So we do the summation of both the cases

    return dp[n][amount] = findans(coins, n, amount - coins[n - 1], dp) + findans(coins, n - 1, amount, dp);
}

int change(vector<int> &coins, int amount)
{

    int n = coins.size();

    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

    return findans(coins, n, amount, dp);
}

int main()
{

    // This problem is an implementation of Unbounded knapsack
    // We have to find the total number of ways of coins required to make an amount
    // We have unlimited supply of each coin

    int n;
    cin >> n;
    int amount;
    cin >> amount;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i)
        cin >> coins[i];

    cout << change(coins, amount) << endl;
    return 0;
}
