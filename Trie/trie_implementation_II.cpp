#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *links[26];
    int countWords = 0;
    int countPrefix = 0;
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        // Trie(): To initialize the object of this “TRIE” data structure.

        root = new Node();
    }

    void insert(string &word)
    {
        //insert(“WORD”): To insert the string “WORD”  into this “TRIE” data structure.

        Node *node = root;
        for (int i = 0; i < word.length(); ++i)
        {
            if (node->links[word[i] - 'a'] == NULL)
            {
                node->links[word[i] - 'a'] = new Node();
            }
            node = node->links[word[i] - 'a'];
            node->countPrefix++;
        }
        node->countWords++;
    }

    int countWordsEqualTo(string &word)
    {
        // countWordsEqualTo(“WORD”): To return how many times this “WORD” is present in this “TRIE”.

        Node *node = root;
        for (int i = 0; i < word.length(); ++i)
        {
            if (node->links[word[i] - 'a'] == NULL)
                return 0;
            else
            {
                node = node->links[word[i] - 'a'];
            }
        }
        return node->countWords;
    }

    int countWordsStartingWith(string &word)
    {
        // countWordsStartingWith(“PREFIX”): To return how many words are there in this “TRIE” that have the string “PREFIX” as a prefix.

        Node *node = root;
        for (int i = 0; i < word.length(); ++i)
        {
            if (node->links[word[i] - 'a'] == NULL)
                return 0;
            else
            {
                node = node->links[word[i] - 'a'];
            }
        }
        return node->countPrefix;
    }

    void erase(string &word)
    {
        // erase(“WORD”): To delete this string “WORD” from the “TRIE”.
        Node *node = root;
        for (int i = 0; i < word.length(); ++i)
        {
            if (node->links[word[i] - 'a'] == NULL)
                return;
            else
            {
                node = node->links[word[i] - 'a'];
                --node->countPrefix;
            }
        }
        --node->countWords;
    }
};

int main()
{

    return 0;
}