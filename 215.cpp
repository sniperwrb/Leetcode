class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int l = nums.size();
		return nums[l - k];
	}
};