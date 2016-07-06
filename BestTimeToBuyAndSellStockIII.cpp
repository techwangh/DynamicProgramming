//TLE
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices.size();
        if(m == 0) return 0;
        int res = 0;
        vector<int> diffs(m, 0);
        for(int i = 1; i < m; ++i) {
        	diffs[i] = prices[i] - prices[i-1];
        }
        for(int i = 0; i < m-1; ++i) {
            res = max(res, maxSubarray(diffs, 0, i) + maxSubarray(diffs, i+1, m-1));
        }
        return res;
    }

    int maxSubarray(vector<int> arr, int start, int end) {
        if(arr.size() == 0 || start < end) return 0;
        int res = arr[start], tmp = arr[start];
        for(int i = start+1; i <= end; ++i) {
            tmp = max(tmp+arr[i], arr[i]);
            res = max(res, tmp);
        }
        return res;
    }
};

//DP
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int maxTransactionTimes = 2;
        vector<vector<int>> dp(maxTransactionTimes+1, vector<int>(prices.size(), 0));
        for(int t = 1; t <= maxTransactionTimes; ++t) {
            int tmpMax = dp[t-1][0] - prices[0];
            for(int i = 1; i < prices.size(); ++i) {
                dp[t][i] = max(dp[t][i-1], prices[i] + tmpMax);
                tmpMax = max(tmpMax, dp[t-1][i] - prices[i]);
            }
        }
        return dp[maxTransactionTimes][prices.size()-1];
    }
};
