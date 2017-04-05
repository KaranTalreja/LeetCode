/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * 
 * The input nodes values are rearranged into lower and higher value terms.
 * If the rootVal equals any of the value root is returned.
 * If rootVal is lower than the lowest one, then function called on root->right
 * else on left. 
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        int pVal = p->val > q->val ? p->val : q->val;
        int qVal = p->val > q->val ? q->val : p->val;
        int rVal = root->val;
        if (rVal > pVal) return lowestCommonAncestor(root->left, p, q);
        else if (rVal < qVal) return lowestCommonAncestor(root->right, p, q);
        else if (rVal <= pVal && rVal >= qVal) return root; 
    }
};
