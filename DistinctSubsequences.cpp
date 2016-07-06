class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));	//dp[i][j]:t的前i个字符在s的前j个字符中的不同子序列的个数
        for(int j = 0; j <= m; ++j)
        	dp[0][j] = 1;
        for(int i = 1; i <=n; ++i) {
        	for(int j = 1; j <=m; ++j) {
        		if(t[i] == s[j])
        			dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
        		else
        			dp[i][j] = dp[i][j-1];
        	}
        }
        return dp[n][m];
    }
};