class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        
        vector<int> maxMoney;
        maxMoney = nums;
        int res = nums[0];
        for(int i = 1; i < n; ++i) {
            for(int k = 0; k < i-1; ++k) {
                maxMoney[i] = max(maxMoney[i], maxMoney[k]+nums[i]);
            }
            res = max(res, maxMoney[i]);
        }
        return res;
    }
};