#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *links[26];
    bool flag = false;
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
};

class Trie
{
private:
    Node *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Node *node = root;

        for (int i = 0; i < word.length(); ++i)
        {
            if (node->containsKey(word[i]) == false)
            {
                node->links[word[i] - 'a'] = new Node();
            }
            node = node->links[word[i] - 'a'];
        }
        node->flag = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); ++i)
        {
            if (node->containsKey(word[i]) == false)
                return false;
            node = node->links[word[i] - 'a'];
        }
        return node->flag;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.length(); ++i)
        {
            if (node->containsKey(prefix[i]) == false)
                return false;
            node = node->links[prefix[i] - 'a'];
        }
        return true;
    }
};

int main()
{

    return 0;
}