/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	int ec(TreeNode* root) {
		if (root == NULL)
		{
			return 0;
		}
		else
		{
			return ec(root->left) + ec(root->right) + 1;
		}
	}
	int kthSmallest(TreeNode* root, int k) {
		int n = ec(root->left);
		if (k == n + 1)
		{
			return root->val;
		}
		else if (k <= n)
		{
			return kthSmallest(root->left, k);
		}
		else
		{
			return kthSmallest(root->right, k - n - 1);
		}
	}
};