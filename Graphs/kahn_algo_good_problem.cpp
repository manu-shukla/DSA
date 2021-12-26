#include <bits/stdc++.h>
using namespace std;

// Leetcode problem -  Find All Possible Recipes from Given Supplies
// Problem Link - https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/

class Solution
{
public:
    vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
    {
        map<string, set<string>> adj;
        set<string> sups(supplies.begin(), supplies.end());
        vector<string> ans;
        set<string> recp(recipes.begin(), recipes.end());
        map<string, int> indeg;
        for (int i = 0; i < recipes.size(); ++i)
        {
            for (int j = 0; j < ingredients[i].size(); ++j)
            {
                adj[ingredients[i][j]].insert(recipes[i]);
                if (indeg.find(ingredients[i][j]) == indeg.end())
                    indeg[ingredients[i][j]] = 0;
                indeg[recipes[i]]++;
            }
        }

        queue<string> q;
        for (auto it : indeg)
        {
            if (it.second == 0)
                q.push(it.first);
        }
        while (!q.empty())
        {
            string node = q.front();
            q.pop();
            if (recp.find(node) != recp.end())
                ans.push_back(node);

            for (auto child : adj[node])
            {
                if (sups.find(node) != sups.end())
                    --indeg[child];
                if (indeg[child] == 0)
                {
                    q.push(child);
                    sups.insert(child);
                }
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}