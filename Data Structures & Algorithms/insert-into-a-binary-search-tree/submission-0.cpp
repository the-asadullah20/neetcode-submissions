void insert(TreeNode *&root,int val)
{
    if(!root)
    {
        root=new TreeNode(val);
        return;
    }

    if(root->val>val)
        insert(root->left,val);
    else
        insert(root->right,val);
}

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        insert(root,val);
        return root;
    }
};