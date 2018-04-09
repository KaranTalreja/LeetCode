#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <string.h>
#include <algorithm>
#include <list>
#include <queue>
#include <set>
#include <sstream>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
  public:
    int helper (TreeNode* root, map<TreeNode*, int>& DP) {
      if (!root) return INT_MIN;
      int retval = INT_MIN;
      if (root->left == NULL && root->right == NULL) retval = root->val;
      else {
        retval = max(helper(root->left, DP), helper(root->right, DP));
        int rc1 = helperLeafPath(root->left, DP);
        int rc2= helperLeafPath(root->right, DP);
        int rc = INT_MIN;
        if (rc1 != INT_MIN) rc = rc1;
        if (rc2 != INT_MIN) {
          if (rc != INT_MIN) rc += rc2;
          else rc = rc2;
        }
        if (rc > retval) {
          retval = rc + root->val;
        }
        if (root->val > retval) retval = root->val;
      }
      return retval;
    }

    int helperLeafPath(TreeNode* root, map<TreeNode*, int>& DP) {

      if (!root) return INT_MIN;
      if (DP.find(root) != DP.end()) return DP[root];
      int retval = INT_MIN;
      if (root->left == NULL && root->right == NULL) retval = root->val;
      else {
        retval = max( helperLeafPath(root->left, DP), helperLeafPath(root->right, DP)) + root->val;
      }

      DP[root] = retval;
      return retval;
    }

    int maxPathSum(TreeNode* root) {
      map<TreeNode*, int> DP;
      int rc = helper(root, DP);
      return rc;
    }
};

void trimLeftTrailingSpaces(string &input) {
  input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
        }));
}

void trimRightTrailingSpaces(string &input) {
  input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
        }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);
  if (!input.size()) {
    return nullptr;
  }

  string item;
  stringstream ss;
  ss.str(input);

  getline(ss, item, ',');
  TreeNode* root = new TreeNode(stoi(item));
  queue<TreeNode*> nodeQueue;
  nodeQueue.push(root);

  while (true) {
    TreeNode* node = nodeQueue.front();
    nodeQueue.pop();

    if (!getline(ss, item, ',')) {
      break;
    }

    trimLeftTrailingSpaces(item);
    if (item != "null") {
      int leftNumber = stoi(item);
      node->left = new TreeNode(leftNumber);
      nodeQueue.push(node->left);
    }

    if (!getline(ss, item, ',')) {
      break;
    }

    trimLeftTrailingSpaces(item);
    if (item != "null") {
      int rightNumber = stoi(item);
      node->right = new TreeNode(rightNumber);
      nodeQueue.push(node->right);
    }
  }
  return root;
}

int main() {
  string line;
  while (getline(cin, line)) {
    TreeNode* root = stringToTreeNode(line);

    int ret = Solution().maxPathSum(root);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}
