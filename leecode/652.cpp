#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int MAX = 2e9 + 7;
const int N = 2e4 + 5;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

map<string, vector<TreeNode *>> mp;
string toString(TreeNode *root)
{
    if (root == nullptr)
        return "";
    string left = toString(root->left);
    string right = toString(root->right);
    string ans = "L" + left + "W" + to_string(root->val) + "R" + right;
    vector<TreeNode *> tmp;
    if (mp.find(ans) != mp.end())
        tmp = mp[ans];
    tmp.push_back(root);
    mp[ans] = tmp;
    cout << ans << endl;
    return ans;
}

vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
{
    toString(root);
    vector<TreeNode *> result;
    for (auto it : mp)
    {
        if (it.second.size() > 1)
        {
            result.push_back((it.second)[0]);
        }
    }
    return result;
}