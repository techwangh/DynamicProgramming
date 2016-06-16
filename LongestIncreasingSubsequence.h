class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 1;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-1; ++i) {
            if(nums[i+1] > nums[i]) {
                ++res;
            }
        }
        return res;
    }
};