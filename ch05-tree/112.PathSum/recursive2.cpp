class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
		//edge
        if (root == NULL) {
            return false;
        }
        if (root->left == NULL and root->right == NULL) {
            return root->val == sum;
        }
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);        
    }
};