#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    int key;
    Node *prev;
    Node *next;
    Node(int _key, int _val)
    {
        val = _val;
        key = _key;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache
{
private:
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node *> mp;

public:
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node *p)
    {

        p->prev->next = p->next;
        p->next->prev = p->prev;
    }

    void insertNode(Node *p)
    {
        Node *t = head->next;
        p->next = t;
        p->prev = head;
        head->next = p;
        t->prev = p;
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            Node *node = mp[key];
            int val = mp[key]->val;
            mp.erase(key);

            deleteNode(node);
            insertNode(node);
            mp[key] = head->next;

            return val;
        }

        return -1;
    }
    void put(int key, int val)
    {
        if (mp.find(key) != mp.end())
        {
            Node *node = mp[key];
            mp.erase(key);
            deleteNode(node);
        }
        if (mp.size() == cap)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        insertNode(new Node(key, val));
        mp[key] = head->next;
    }
};

int main()
{
    // LRU Cache Implementation

    return 0;
}