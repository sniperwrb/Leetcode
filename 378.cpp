class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		vector<int> v;
		int n = matrix.size();
		int i;
		for (i = 0; i<n; i++)
		{
			v.insert(v.end(), matrix[i].begin(), matrix[i].end());
		}
		sort(v.begin(), v.end());
		return v[k - 1];
	}
};