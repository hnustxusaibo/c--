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
  int deep(TreeNode *root) {
    if (root == nullptr) return 0;
    return max(deep(root->left), deep(root->right)) + 1;
  }

  void def(TreeNode *root, vector<vector<string>> &mp, int x, int y, int dep) {
    if (root == nullptr) return;
    mp[x][y] = to_string(root->val);
    int t = 1 << (dep - x);
    def(root->left, mp, x + 1, y - t, dep);
    def(root->right, mp, x + 1, y + t - 1, dep);
  }

  vector<vector<string>> printTree(TreeNode *root) {
    int dep = deep(root);
    vector<vector<string>> mp;
    for (int i = 0; i < dep; i++) {
      vector<string> s;
      for (int j = 0; j < (1 << dep) - 1; j++) s.push_back("");
      mp.push_back(s);
    }
    def(root, mp, 0, (1 << (dep - 1)) - 1, dep);
    return mp;
  }
};
