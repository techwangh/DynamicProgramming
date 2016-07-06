class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        //best time to buy and sell stock II
        if(k >= prices.size()/2) {
            int res = 0;
            for(int i = 1; i < prices.size(); ++i) {
                if(prices[i] - prices[i-1] > 0) {
                    res += prices[i] - prices[i-1];
                }
            }
            return res;
        }        

        vector<vector<int>> dp(k+1, vector<int>(prices.size(), 0));
        for(int t = 1; t <= k; ++t) {
            int tmpMax = dp[t-1][0] - prices[0];
            for(int i = 1; i < prices.size(); ++i) {
                dp[t][i] = max(dp[t][i-1], prices[i] + tmpMax);
                tmpMax = max(tmpMax, dp[t-1][i] - prices[i]);
            }
        }
        return dp[k][prices.size()-1];
    }
};