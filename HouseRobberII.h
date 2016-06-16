class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        
        return max(getMaxMoney(nums,0,n-2), getMaxMoney(nums,1,n-1));
    }
    
    int getMaxMoney(vector<int>& nums, int start, int end) {
        vector<int> maxMoney;
        maxMoney = nums;
        int res = nums[start];
        for(int i = start+1; i <= end; ++i) {
            for(int k = start; k < i-1; ++k) {
                maxMoney[i] = max(maxMoney[i], maxMoney[k]+nums[i]);
            }
            res = max(res, maxMoney[i]);
        }
        return res;
    }
};