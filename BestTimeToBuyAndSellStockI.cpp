class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if(prices.size() == 0) return 0;
        vector<int> diffs(prices.size(), 0);
        for(int i = 1; i < prices.size(); ++i) {
        	diffs[i] = prices[i] - prices[i-1];
        }
        return maxSubarray(diffs);
    }

    int maxSubarray(vector<int> arr) {
    	if(arr.size() == 0) return 0;
    	int res = arr[0], tmp = arr[0];
    	for(int i = 1; i < arr.size(); ++i) {
    		tmp = max(tmp+arr[i], arr[i]);
    		res = max(res, tmp);
    	}
    	return res;
    }
};


//better solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if(prices.size() == 0) return 0;
    	int res = 0, minPrice = prices[0];
        for(int i = 0; i < prices.size(); ++i) {
            minPrice = min(minPrice, prices[i]);
            res = max(res, prices[i] - minPrice);
        }
        return res;
    }
};

