#include <bits/stdc++.h>
using namespace std;

bool subsetSum(int arr[], int sum, int n, vector<vector<int>> &dp)
{
    if (sum == 0)
        return true;
    if (n == 0)
        return false;

    if (dp[n][sum] != -1)
        return dp[n][sum];

    if (arr[n - 1] > sum)
    {
        return dp[n][sum] = subsetSum(arr, sum, n - 1, dp);
    }

    return dp[n][sum] = (subsetSum(arr, sum - arr[n - 1], n - 1, dp) || subsetSum(arr, sum, n - 1, dp));
}

bool isSubsetSum(int N, int arr[], int sum)
{

    vector<vector<int>> dp(N + 1, vector<int>(sum + 1, -1));

    return subsetSum(arr, sum, N, dp);
}
int main()
{
    // This problem is a variation of the 0-1 Knapsack problem. In this problem, we need to find if there exists a subset whose sum of elements is equal to the target sum.

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int sum;
    cin >> sum;

    if (isSubsetSum(n, arr, sum))
    {
        cout << "There exists atleast one subset whose sum of elements is equal to the 'sum'" << endl;
    }
    else
    {
        cout << "There is no subset whose sum of elements is equal to the 'sum'" << endl;
    }

    return 0;
}