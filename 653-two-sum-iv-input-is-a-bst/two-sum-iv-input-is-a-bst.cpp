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
    stack<TreeNode*> asc;
    stack<TreeNode*> dsc;

    TreeNode* getSmall() {
        if (asc.empty())
            return NULL;

        TreeNode* small = asc.top();
        asc.pop();

        TreeNode* rightChild = small->right;

        while (rightChild) {
            asc.push(rightChild);
            rightChild = rightChild->left;
        }
        return small;
    }

    TreeNode* getBig() {
        if (dsc.empty())
            return NULL;

        TreeNode* big = dsc.top();
        dsc.pop();

        TreeNode* leftChild = big->left;

        while (leftChild) {
            dsc.push(leftChild);
            leftChild = leftChild->right;
        }
        return big;
    }

    bool findTarget(TreeNode* root, int k) {
        if (root == NULL) {
            return false;
        }

        TreeNode* t = root;

        while (t) {
            asc.push(t);
            t = t->left;
        }

        t = root;

        while (t) {
            dsc.push(t);
            t = t->right;
        }

        TreeNode* i = getSmall();
        TreeNode* j = getBig();

        while (i && j && i != j) {
            int sum = i->val + j->val;
            if (sum == k)
                return true;

            if (sum > k)
                j = getBig();
            else
                i = getSmall();
        }
        return false;
    }
};