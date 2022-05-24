#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int d = 10; // Hashing multiplier (Weight)

void rabinKarp(string &s, string &p)
{
    int m = p.length();
    int n = s.length();

    int h = 1; // precompute the value of d^(m-2);

    int patternHash = 0;
    int stringHash = 0;

    for (int i = 1; i <= m - 1; ++i)
    {
        h = (h * d) % mod;
    }

    // Calculating the hash value of pattern and string for window size m;

    for (int i = 0; i < m; ++i)
    {
        patternHash = (d * patternHash + p[i]) % mod;
        stringHash = (d * stringHash + s[i]) % mod;
    }

    for (int i = 0; i <= n - m; ++i)
    {
        if (stringHash == patternHash) // Superious Hit
        {
            bool flag = true;
            for (int j = 0; j < m; ++j)
                if (s[i + j] != p[j])
                {
                    flag = false;
                    break;
                }
            if (flag)
            {
                cout << "Index at: " << i << " is a match" << endl;
            }
        }
        if (i < n - m)
        {
            stringHash = (d * (stringHash - s[i] * h) + s[i + m]) % mod;
            if (stringHash < 0)
            {
                stringHash += mod;
            }
        }
    }
}

int main()
{

    // This algorithm is used to find all the occurances of a string in a string (all patterns in a string)
    // This algorithm uses hashing technique to find the occurances

    string s, p;
    cin >> s >> p;

    rabinKarp(s, p);

    return 0;
}