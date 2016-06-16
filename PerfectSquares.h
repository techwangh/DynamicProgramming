class Solution {
public:
    int numSquares(int n) {
        int m = sqrt(n);
        vector<int> nums(m,0);
        vector<int> counts(n+1,INT_MAX);
        counts[0] = 0;
        for(int i = 1; i <= m; ++i) {
            nums[i-1] = i*i;
        }
        for(int i = 1; i <= n; ++i) {
            for(int k = 0; k < m; ++k) {
                if(i >= nums[k]) {
                    counts[i] = min(counts[i], counts[i-nums[k]]+1);
                }
            }
        }
        return counts[n];
    }
};