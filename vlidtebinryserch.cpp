class Solution {
public:
    TreeNode* prev = NULL;
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        if(isValidBST(root->left)==false) return false;
        if( prev!=NULL && root->val <= prev->val) return false;
        prev = root;
        return isValidBST(root->right);
    }
};
