#include <bits/stdc++.h>
using namespace std;
class Node
{

public:
    Node *links[26];
    bool flag = false;
};

void insert(Node *root, string &word)
{
    Node *node = root;

    for (int i = 0; i < word.length(); ++i)
    {
        if (node->links[word[i] - 'a'] == NULL)
        {
            node->links[word[i] - 'a'] = new Node();
        }
        node = node->links[word[i] - 'a'];
    }

    node->flag = true;
}

bool search(Node *root, string &s)
{
    Node *node = root;

    for (int i = 0; i < s.length(); ++i)
    {
        if (node->links[s[i] - 'a'] == NULL || node->links[s[i] - 'a']->flag == false)
            return false;
        node = node->links[s[i] - 'a'];
    }
    return true;
}

string completeString(int n, vector<string> &a)
{

    Node *root = new Node();
    sort(a.begin(), a.end());
    int len = INT_MIN;
    string ans = "";
    for (int i = 0; i < n; ++i)
    {
        insert(root, a[i]);
    }
    for (int i = 0; i < n; ++i)
    {

        if (search(root, a[i]))
        {
            if (len < (int)a[i].length())
            {
                len = (int)a[i].length();
                ans = a[i];
            }
        }
    }
    if (ans == "")
        return "None";

    return ans;
}

int main()
{
    //A string is called a complete string if every prefix of this string is also present in the array ‘A’. Ninja is challenged to find the longest complete string in the array ‘A’.If there are multiple strings with the same length, return the lexicographically smallest one and if no string exists, return "None".

    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    cout << completeString(n, a) << endl;

    return 0;
}