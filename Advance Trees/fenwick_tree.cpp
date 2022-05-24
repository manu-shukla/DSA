#include <bits/stdc++.h>
using namespace std;

int findLowerBound(int k, vector<int> &fen)
{
    int curr = 0, ans = 0, prevsum = 0;
    for (int i = log2((int)fen.size()); i >= 0; --i)
    {
        if (fen[curr + (1 << i)] + prevsum < k)
        {
            curr += (1 << i);
            prevsum += fen[curr];
        }
    }
    return curr;
}

void update(int i, int add, vector<int> &fen)
{
    int n = fen.size();
    while (i < n)
    {
        fen[i] += add;
        i += (i & (-i));
    }
}

int sum(int i, vector<int> &fen)
{
    int s = 0;
    while (i > 0)
    {
        s += fen[i];
        i = i - (i & (-i));
    }
    return s;
}

int main()
{

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    vector<int> fen(n + 1, 0);

    for (int i = 0; i < n; ++i)
    {
        update(i + 1, arr[i], fen);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            // get sum in range [l,r]
            int l, r;
            cin >> l >> r;
            cout << sum(r, fen) - sum(l - 1, fen) << endl;
        }
        else if (x == 1)
        {
            // update by adding t to index i;
            // 1 based indexing
            int t, idx;
            cin >> t >> idx;
            update(idx, t, fen);
        }
        else if (x == 2)
        {
            // find lower bound of the prefix sum < k
            int k;
            cin >> k;
            cout << findLowerBound(k, fen) << endl;
        }
    }

    return 0;
}