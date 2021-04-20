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

	// A stack to facilitate the pre-order traversal
	stack<TreeNode*> pending_nodes;
	pending_nodes.push(root);

	// A map to save node and the root-to-it sum pair
	map<TreeNode*, int> sums;
	sums[root] = root->val;

	while (!pending_nodes.empty())
	{
		TreeNode* node = pending_nodes.top();
		pending_nodes.pop();

		// Encounter a leaf node
		if (node->left == nullptr && node->right == nullptr)
		{
			if (sums[node] == targetSum)
			{
				return true;
			}
		}

		// It doesn't really matter in this case, but for a good pre-order
		// traversal, put right child to stack first. 
		if (node->right != nullptr)
		{
			sums[node->right] = sums[node] + node->right->val;
			pending_nodes.push(node->right);
		}

		if (node->left != nullptr)
		{
			sums[node->left] = sums[node] + node->left->val;
			pending_nodes.push(node->left);
		}
	}

	return false;
}