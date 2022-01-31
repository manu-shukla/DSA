#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}

class Node
{
public:
    Node *links[2];
};

class Trie
{

private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(int x)
    {
        Node *node = root;

        for (int i = 31; i >= 0; --i)
        {
            int bit = (x & (1 << i)) ? 1 : 0;

            if (node->links[bit] == NULL)
                node->links[bit] = new Node();

            node = node->links[bit];
        }
    }
    int getMax(int x)
    {
        Node *node = root;
        int num = 0;
        for (int i = 31; i >= 0; --i)
        {
            int bit = (x >> i) & 1;

            if (node->links[!bit] != NULL)
            {
                num |= (1 << i);

                node = node->links[!bit];
            }

            else if (node->links[bit] != NULL)
            {
                node = node->links[bit];
            }
            else
                return -1;
        }
        return num;
    }
};

vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &q)
{

    vector<vector<int>> nq;

    Trie *obj = new Trie();

    for (int i = 0; i < q.size(); ++i)
    {
        nq.push_back({q[i][0], q[i][1], i});
    }
    sort(nq.begin(), nq.end(), cmp);
    sort(nums.begin(), nums.end());
    int idx = 0;
    vector<int> ans(q.size());
    for (int i = 0; i < nq.size(); ++i)
    {
        while (idx < nums.size() && nums[idx] <= nq[i][1])
        {
            obj->insert(nums[idx]);
            ++idx;
        }

        ans[nq[i][2]] = obj->getMax(nq[i][0]);
    }
    return ans;
}

int main()
{
    // You are given an array/list ‘ARR’ consisting of ‘N’ non-negative integers. You are also given a list ‘QUERIES’ consisting of ‘M’ queries, where the ‘i-th’ query is a list/array of two non-negative integers ‘Xi’, ‘Ai’, i.e ‘QUERIES[i]’ = [‘Xi’, ‘Ai’].

    // The answer to the ith query, i.e ‘QUERIES[i]’ is the maximum bitwise xor value of ‘Xi’ with any integer less than or equal to ‘Ai’ in ‘ARR’.You should return an array / list consisting of ‘N’ integers where the ‘i - th’ integer is the answer of ‘QUERIES[i]’.

    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    vector<vector<int>> queries(q, vector<int>(2));
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    for (int i = 0; i < q; ++i)
        cin >> queries[i][0] >> queries[i][1];

    vector<int> ans = maximizeXor(nums, queries);

    for (int i = 0; i < q; ++i)
        cout << ans[i] << " ";

    cout << endl;

    return 0;
}