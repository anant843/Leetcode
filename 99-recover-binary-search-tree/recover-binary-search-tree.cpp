/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* prev=NULL;
    TreeNode* g1f=NULL;
    TreeNode* g1s=NULL;
    TreeNode* g2f=NULL;
    TreeNode* g2s=NULL;
    int g=0;

    void fun(TreeNode* root){
        if(root==NULL)
        return;

        fun(root->left);

        if(prev==NULL)
         prev=root;

         else{
            if(prev->val>root->val){
                if(g==0){
                    g1f=prev;
                    g1s=root;
                    g++;
                }
                else{
                    g2f=prev;
                    g2s=root;
                    g++;
                }
            }
            prev=root;
         }
      fun(root->right);
    }

    void recoverTree(TreeNode* root) {
      fun(root);
      if(g==1){
        swap(g1f->val,g1s->val);
      }
      else{
         swap(g1f->val,g2s->val);
      }
    }
};