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
      TreeLinkNode* currNode = root;
      TreeLinkNode* nextLevelPrev = NULL;
      TreeLinkNode* nextLevelHead = NULL;
      while (NULL != currNode) {
        while (NULL != currNode) {
          if (NULL != currNode->left) {
            if (NULL == nextLevelHead) nextLevelHead = currNode->left;
            if (NULL != nextLevelPrev) nextLevelPrev->next = currNode->left;
            nextLevelPrev = currNode->left;
          }
          if (NULL != currNode->right) {
            if (NULL == nextLevelHead) nextLevelHead = currNode->right;
            if (NULL != nextLevelPrev) nextLevelPrev->next = currNode->right;
            nextLevelPrev = currNode->right;
          }
          currNode = currNode->next;
        }
        currNode = nextLevelHead;
        nextLevelHead = NULL;
        nextLevelPrev = NULL;
      }
    }
};
