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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> a,b,c;
        vector<int> d;
        int l,r,i,j,s,x;
        if (root==NULL)
        {
            return a;
        }
        b=levelOrder(root->left);
        c=levelOrder(root->right);
        l=b.size();
        r=c.size();
        d.push_back(root->val);
        a.push_back(d);
        if (l<r)
        {
            for (i=0;i<l;i++)
            {
                s=c[i].size();
                for (j=0;j<s;j++)
                {
                    b[i].push_back(c[i][j]);
                }
                a.push_back(b[i]);
            }
            for (i=l;i<r;i++)
            {
                a.push_back(c[i]);
            }
        }
        else
        {
            for (i=0;i<r;i++)
            {
                s=c[i].size();
                for (j=0;j<s;j++)
                {
                    b[i].push_back(c[i][j]);
                }
                a.push_back(b[i]);
            }
            for (i=r;i<l;i++)
            {
                a.push_back(b[i]);
            }
        }
        return a;
    }
};