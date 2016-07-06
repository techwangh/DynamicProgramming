class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int res = 0;
        vector<int> diffs(prices.size(), 0);
        for(int i = 1; i < prices.size(); ++i) {
        	diffs[i] = prices[i] - prices[i-1];
        	if(diffs[i] > 0)
        		res += diffs[i];
        }
        return res;
    }
};