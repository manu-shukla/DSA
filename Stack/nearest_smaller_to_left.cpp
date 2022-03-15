#include <bits/stdc++.h>
using namespace std;

vector<int> findNSL(vector<int> &arr, int n)
{
    vector<int> ans(n);

    stack<int> st;

    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && st.top() >= arr[i])
            st.pop();
        if (st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();

        // The current stack after the above operation will always contain elements less than arr[i].

        st.push(arr[i]);
    }
    return ans;
}

int main()
{
    // We have to find the nearest smaller number to the left of the current number at which we are standing

    // Example :
    // For 1 3 2 4
    // ans is -1 1 1 2

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    vector<int> ans = findNSL(arr, n);

    for (int i = 0; i < n; ++i)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}