
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
		TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool hasPathSum(TreeNode* root, int targetSum)
{
	if (root == nullptr)
	{
		return false;
	}

	int sum = 0;
	return helper(root, sum, targetSum);
}

bool helper(TreeNode* root, int& sum, int& targetSum)
{
	sum += root->val;
	if (root->left == nullptr && root->right == nullptr)
	{
		if (sum == targetSum)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int left_sum = sum;
	if (root->left != nullptr && helper(root->left, left_sum, targetSum))
	{
		return true;
	}

	int right_sum = sum;
	if (root->right != nullptr && helper(root->right, right_sum, targetSum))
	{
		return true;
	}

	return false;
}
