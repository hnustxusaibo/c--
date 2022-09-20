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

int ans = 0;
int dfs(TreeNode *root)
{
    int l = 0, r = 0;
    if (root->left != nullptr)
    {
        l = dfs(root->left);
        if (root->left->val != root->val)
            l = 0;
    }
    if (root->right != nullptr)
    {
        r = dfs(root->right);
        if (root->right->val != root->val)
            r = 0;
    }
    ans = max(ans, l + r + 1);
    return max(l, r) + 1;
}

int longestUnivaluePath(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    dfs(root);
    return ans - 1;
}