/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
  public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      if (!root) return "";
      vector<TreeNode*> q;
      string retval;
      retval += std::to_string(root->val);
      retval += ",";
      q.push_back(root);
      while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
          TreeNode* curr = q.back();
          //cout << curr->val << ",";
          q.pop_back();
          if (curr->left) {
            q.insert(q.begin(),curr->left);
          }
          if (curr->right)  {
            q.insert(q.begin(),curr->right);
          }
          if (curr->left) {
            retval += std::to_string(curr->left->val);
            retval += ",";
          } else {
            retval += "@,";
          }
          if (curr->right) {
            retval += std::to_string(curr->right->val);
            retval += ",";
          } else {
            retval += "@,";
          }
        }
      }
      //cout << endl <<retval << endl;
      return retval;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
      int size = data.size();
      if (!size) return NULL;
      vector<TreeNode*> q;
      int i = 0;
      for (int i = 0; i < size; i++) {
        int j = i;
        while (data[j] != ',') j++;
        if (data.substr(i,j-i).compare("@")) q.push_back(new TreeNode(std::stoi(data.substr(i,j-i))));
        else q.push_back(NULL);
        i = j;
      }
      int j = 1;
      TreeNode* root = q[0];
      TreeNode* curr = NULL;
      for (i=0; i < q.size(); i++) {
        if (!q[i]) continue;
        curr = q[i];
        curr->left = q[j];
        curr->right = q[j+1];
        j+=2;
      }
      return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
