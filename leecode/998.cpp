#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int MAX = 2e9 + 7;
const int N = 1e3 + 5;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode *insertIntoMaxTree(TreeNode *root, int val) {
    if (root->val < val) {
      TreeNode *p = new TreeNode(val, root, nullptr);
      printf("a");
      return p;
    }
    if (root->right == nullptr || root->right->val < val) {
      TreeNode *p = new TreeNode(val, root->right, nullptr);
      root->right = p;
      printf("b");
      return root;
    }
    insertIntoMaxTree(root->right, val);
    printf("c");
    return root;
  }
};