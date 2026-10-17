/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int idx;
    TreeNode* fun(vector<int>& postorder, int low, int high,
                  unordered_map<int, int>& mp) {
        if (low > high)
            return NULL;

        TreeNode* node = new TreeNode(postorder[idx]);
        idx--;

        int id = mp[node->val];

        node->right = fun(postorder, id + 1, high, mp);
        node->left = fun(postorder, low, id - 1, mp);

        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;

        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        idx = postorder.size() - 1;

        return fun(postorder, 0, inorder.size() - 1, mp);
    }
};