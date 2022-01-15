#include <bits/stdc++.h>
using namespace std;

int mcm(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
{
    // When size of the arr is 1 then there can be only one matrix available and thus multiplication is not possible
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    // We will partition the array into k different subgroups for current i -> j
    for (int k = i; k < j; ++k)
    {
        int curr = mcm(arr, i, k, dp) + mcm(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];
        /* If k = 2, i =1, j = n-1     I   \  II \ Matrix Obtained after I and II
        For the above code:A*B*C*D->(A*B*C)\*(D) \ -> A*C*D 
        */

        ans = min(ans, curr);
    }

    return dp[i][j] = ans;
}

int main()
{

    // In this problem, we are given a matrices size and we need to put them in a order of multiplication (by putting brackets) such that the total operations of multiplications is minimized

    /* Suppose,
            Matrix A - a x b
                and 
            Matrix B - b x c
        
        So, the total number of multiplications of elements to be done for obtaining matrix A x B will be a x b x c. 


    The Problem statement is: 

    Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

    The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]). 

*/

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << mcm(arr, 1, n - 1, dp) << endl;

    return 0;
}