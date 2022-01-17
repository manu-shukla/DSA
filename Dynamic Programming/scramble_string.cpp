#include <bits/stdc++.h>
using namespace std;
bool solve(string a, string b, map<string, bool> &dp)
{
    if (a == b)
        return true;

    if (a.length() <= 1)
        return false;

    string key = a + " " + b;
    if (dp.find(key) != dp.end())
        return dp[key];

    int len = a.length();
    bool check = false;
    for (int i = 1; i < len; ++i)
    {
        if ((solve(a.substr(0, i), b.substr(len - i, i), dp) && solve(a.substr(i, len - i), b.substr(0, len - i), dp)) || (solve(a.substr(0, i), b.substr(0, i), dp) && solve(a.substr(i, len - i), b.substr(i, len - i), dp)))
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