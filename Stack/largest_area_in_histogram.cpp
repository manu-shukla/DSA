#include <bits/stdc++.h>
using namespace std;

int largestArea(vector<int> &arr, int n)
{

    stack<pair<int, int>> s1, s2;

    vector<int> left, right;

    // Left denotes nearest smaller to the left of the element where we are currently standing. It contains the indexes of the NSLs.

    // Simlarly, Right denotes the nearest smaller to the right of the element where we are currently standing. It contains the indexes of the NSRs.

    for (int i = 0; i < n; ++i)
    {
        while (!s1.empty() && s1.top().first >= arr[i])
        {
            s1.pop();
        }

        if (s1.empty())
            left.push_back(-1);
        else
            left.push_back(s1.top().second);

        s1.push({arr[i], i});
    }

    for (int i = n - 1; i >= 0; --i)
    {
        while (!s2.empty() && s2.top().first >= arr[i])
            s2.pop();

        if (s2.empty())
            right.push_back(n);
        else
            right.push_back(s2.top().second);

        s2.push({arr[i], i});
    }

    reverse(right.begin(), right.end());

    int ans = 0;

    // Difference in the right and left of a index gives the width of the rectangle.
    // Its height will be height at current index.

    for (int i = 0; i < n; ++i)
        ans = max(ans, arr[i] * (right[i] - left[i] - 1));

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> heights(n);

    for (int i = 0; i < n; ++i)
        cin >> heights[i];

    cout << largestArea(heights, n) << endl;

    return 0;
}