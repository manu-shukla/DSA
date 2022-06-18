#include <bits/stdc++.h>
using namespace std;
bool solve(string A, string B, map<string, bool> &dp)
{
    if (A == B)
        return true;

    if (A.length() <= 1)
        return false;

    string key = A + " " + B;
    if (dp.find(key) != dp.end())
        return dp[key];

    int len = A.length();
    bool check = false;
    for (int i = 1; i < len; ++i)
    {
        // if Swapping done at current length i.e.
        // A-great and B-eatgr
        // Swapping at length 2 i.e. i==2
        // Partitioning A => gr|eat and B=>eat|gr
        // And recursively checking
        // if left of A == right of B and right of A == left of B
        bool swapped = solve(A.substr(0, i), B.substr(len - i), dp) && solve(A.substr(i), B.substr(0, len - i), dp);
        // ************************************************************************
        // No Swapping is done at current length
        // A-great and B-great
        // Partitioning A=>gr|eat and B=>gr|eat
        // recursively checking if
        // left of A == left of B and right of A == right of B
        bool notSwapped = solve(A.substr(0, i), B.substr(0, i), dp) && solve(A.substr(i), B.substr(i), dp);

        if (swapped || notSwapped)
        {
            check = true;
            break;
        }
    }
    return dp[key] = check;
}

int main()
{

    string A, B;
    cin >> A >> B;

    map<string, bool> dp;

    if (solve(A, B, dp))
    {
        cout << "String is Scrambled" << endl;
    }
    else
    {
        cout << "String is NOT Scrambled" << endl;
    }
}