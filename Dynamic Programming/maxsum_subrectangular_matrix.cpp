#include <bits/stdc++.h>
using namespace std;

vector<int> kadane(vector<int> &arr)
{
    int l = 0, r = 0;
    int sum = 0;
    int maxSum = INT_MIN;
    pair<int, int> ans = {-1, -1};
    for (int i = 0; i < arr.size(); ++i)
    {
        sum += arr[i];

        if (sum > maxSum)
        {
            maxSum = sum;
            ans.first = l, ans.second = r;
        }
        if (sum < 0)
        {
            ++l;
            r = l;
            sum = 0;
        }
    }
    return {maxSum, ans.first, ans.second};
}

void maxSumSubmatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int maxLeft = -1, maxRight = -1, maxUp = -1, maxDown = -1;
    int maxSum = INT_MIN;
    int currSum = 0;
    vector<int> dp(n, 0);
    int l = 0, r = 0;
    while (l < m)
    {
        while (r < m)
        {
            for (int i = 0; i < n; ++i)
                dp[i] += matrix[i][r];

            vector<int> sum = kadane(dp);
            if (sum[0] > maxSum)
            {
                maxSum = sum[0];
                maxLeft = l;
                maxRight = r;
                maxUp = sum[1];
                maxDown = sum[2];
            }
            ++r;
        }
        dp = vector<int>(n, 0);
        ++l;
        r = l;
    }

    cout << maxSum << endl;
    cout << maxLeft << " " << maxUp << " " << maxDown << " " << maxRight << endl;
}

int main()
{
    // This program helps to find the maximum sum subrectangular sub matrix in a matrix;

    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> matrix[i][j];

    maxSumSubmatrix(matrix);

    return 0;
}