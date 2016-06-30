class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0) return 0;
        int n = obstacleGrid[0].size();
        if(n == 0) return 0;

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[1][0] = 1;
        for(int i = 0; i < m; ++i) {
        	for(int j = 0; j < n; ++j) {
        		if(obstacleGrid[i][j] == 1) 
        			continue;
        		else
        			dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1];
        	}
        }
        return dp[m][n];
    }
};