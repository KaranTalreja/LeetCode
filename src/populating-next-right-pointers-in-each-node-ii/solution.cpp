/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
  public:
    void connect(TreeLinkNode *root) {
      if (root == NULL) return;
      list<TreeLinkNode*> level;
      level.push_back(root);
      while (!level.empty()) {
        int size = level.size();
        TreeLinkNode* prevNode = NULL;
        for (int i = 0; i < size; i++) {
          TreeLinkNode* currNode = level.front();
          level.pop_front();
          if (NULL != currNode->left) level.push_back(currNode->left);
          if (NULL != currNode->right) level.push_back(currNode->right);
          if (NULL != prevNode) prevNode->next = currNode;
          prevNode = currNode;
        }
      }
    }
};
