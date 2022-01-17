#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;

int helper(string s, int i, int j, bool isTrue)
{

    //base cases
    if (i > j)
        return 0; //or return false

    if (i == j)
    {
        if (isTrue == true)
        {
            return s[i] == 'T';
        }
        else
        {
            return s[i] == 'F';
        }
    }

    //cheking in the hashmap
    string key = to_string(i) + " " + to_string(j) + " " + to_string(isTrue);

    if (mp.find(key) != mp.end())
        return mp[key];

    //recursive case
    int ans = 0;

    for (int k = i + 1; k < j; k = k + 2)
    {

        int lt = helper(s, i, k - 1, true);
        int lf = helper(s, i, k - 1, false);
        int rt = helper(s, k + 1, j, true);
        int rf = helper(s, k + 1, j, false);

        //xor operator
        if (s[k] == '^')
        {
            if (isTrue == true)
            {
                ans += (lt * rf + lf * rt);
            }

            else
            {
                ans += (lt * rt + lf * rf);
            }
        }

        //or operator
        else if (s[k] == '|')
        {
            if (isTrue == true)
            {
                ans += (lt * rt + lt * rf + lf * rt);
            }

            else
            {
                ans += (lf * rf);
            }
        }

        //and operator
        else
        {
            if (isTrue == true)
            {
                ans += (lt * rt);
            }

            else
            {
                ans += (lf * rf + lt * rf + lf * rt);
            }
        }
    }

    return mp[key] = ans;
}
int countWays(int n, string s)
{
    return helper(s, 0, n - 1, true);
}
int main()
{
    /* 
    Given a boolean expression S of length N with following symbols.
Symbols
    'T' ---> true
    'F' ---> false
and following operators filled between symbols
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

*/

    string s;
    cin >> s;
    int n = s.length();

    cout << countWays(n, s) << endl;

    return 0;
}