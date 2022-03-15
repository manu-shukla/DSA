#include <bits/stdc++.h>
using namespace std;

vector<int> findNGR(vector<int> &arr, int n)
{
    vector<int> ans(n);

    stack<int> st;

    for (int i = n - 1; i >= 0; --i)
    {
        while (!st.empty() && st.top() <= arr[i])
            st.pop();
        if (st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();

        // The current stack after the above operation will always contain elements greater than arr[i].

        st.push(arr[i]);
    }
    return ans;
}

int main()
{
    // We have to find the nearest greater number to the right of the current number at which we are standing

    // Example :
    // For 1 2 4 3 6 5
    // ans is : 2 4 6 6 -1 -1

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    vector<int> ans = findNGR(arr, n);

    for (int i = 0; i < n; ++i)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}