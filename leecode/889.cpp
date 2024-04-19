#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int MAX = 2e9 + 7;
const int N = 1e3 + 5;

int dp[55][55][105];

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder) {
    if (preorder.empty()) return nullptr;

    TreeNode *root = new TreeNode(preorder[0]);

    if (preorder.size() == 1) return root;

    int leftRootVal = preorder[1];
    int leftRootIdx = -1;
    for (int i = 0; i < postorder.size(); ++i) {
        if (postorder[i] == leftRootVal) {
            leftRootIdx = i;
            break;
        }
    }

    vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 2 + leftRootIdx);
    vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftRootIdx + 1);

    root->left = constructFromPrePost(leftPreorder, leftPostorder);

    vector<int> rightPreorder(preorder.begin() + 2 + leftRootIdx, preorder.end());
    vector<int> rightPostorder(postorder.begin() + leftRootIdx + 1, postorder.end() - 1);

    root->right = constructFromPrePost(rightPreorder, rightPostorder);

    return root;
}