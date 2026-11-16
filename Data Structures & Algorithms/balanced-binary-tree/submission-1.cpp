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
int depth(TreeNode*root)
{
    if(!root) return 0;
    int left=depth(root->left);
    int right=depth(root->right);
    return 1+max(left,right);
}
void check(TreeNode *root,bool&flag)
{
    if(!root) return;
    int left=depth(root->left);
    int right=depth(root->right);
    if(abs(left-right)>1)
    {
        flag=false;
    }
    check(root->left,flag);
    check(root->right,flag);
}
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        check(root,ans);
        return ans;
    }
};
