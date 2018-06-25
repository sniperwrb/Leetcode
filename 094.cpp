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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> v;
		if (root == NULL)
		{
			return v;
		}
		vector<TreeNode*> p;
		int l;
		TreeNode *t = new TreeNode(0);
		t->left = root;
		t->right = root;
		p.push_back(t);
		l = 1;
		while (l>0)
		{
			if (p[l - 1]->right != NULL) // push phase
			{
				p.push_back(p[l - 1]->right);
				l++;
				while (p[l - 1]->left != NULL)
				{
					p.push_back(p[l - 1]->left);
					l++;
				}
				v.push_back(p[l - 1]->val);
			}
			else // pop phase
			{
				while (p[l - 2]->left != p[l - 1])
				{
					p.pop_back();
					l--;
				}
				p.pop_back();
				l--;
				if (l >= 2)
				{
					v.push_back(p[l - 1]->val);
				}
				else
				{
					l = -1;
				}
			}
		}
		return v;
	}
};