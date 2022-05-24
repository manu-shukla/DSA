#include <bits/stdc++.h>
using namespace std;

void buildTree(int idx, int start, int end, vector<int> &st, vector<int> &arr)
{
    if (start == end)
    {
        st[idx] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    buildTree(2 * idx + 1, start, mid, st, arr);
    buildTree(2 * idx + 2, mid + 1, end, st, arr);

    st[idx] = min(st[2 * idx + 1], st[2 * idx + 2]);
}

void update(int idx, int start, int end, int updateIdx, vector<int> &st, vector<int> &arr)
{
    if (start == end)
    {
        st[idx] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    if (updateIdx <= mid)
    {
        update(2 * idx + 1, start, mid, updateIdx, st, arr);
    }
    else
    {
        update(2 * idx + 2, mid + 1, end, updateIdx, st, arr);
    }

    st[idx] = min(st[2 * idx + 1], st[2 * idx + 2]);
}

int query(int idx, int start, int end, int l, int r, vector<int> &st)
{
    if (start > r || end < l)
        return INT_MAX;

    if (start >= l && end <= r)
        return st[idx];

    int mid = (start + end) / 2;
    int left = query(2 * idx + 1, start, mid, l, r, st);
    int right = query(2 * idx + 2, mid + 1, end, l, r, st);

    return min(left, right);
}

int main()
{
    // This implementation builds segment tree for minimum range query.

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    vector<int> st(4 * n + 4, INT_MAX);
    buildTree(0, 0, n - 1, st, arr);

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;

        cout << query(0, 0, n - 1, l, r, st) << endl;
    }

    return 0;
}