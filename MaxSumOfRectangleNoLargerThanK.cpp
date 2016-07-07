//O[min(m,n)^2 * max(m,n) * log(max(m,n))]
//reference:https://discuss.leetcode.com/topic/48875/accepted-c-codes-with-explanation-and-references
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        int res = INT_MIN;
        for(int l = 0; l < cols; ++l) {
        	vector<int> sums(rows, 0);
        	for(int r = l; r < cols; ++r) {
        	    
                for(int i = 0; i < rows; ++i) {
                	sums[i] += matrix[i][r];
                }

        		int curSum = 0, maxSum = INT_MIN;
        		set<int> accuSet;
        		accuSet.insert(0);
        		for(int sum : sums) {
        			curSum += sum;
        			set<int>::const_iterator it = accuSet.lower_bound(curSum - k);
        			if(it != accuSet.end())
        				maxSum = max(maxSum, curSum - *it);
        			accuSet.insert(curSum);
        		}
        		res = max(res, maxSum);
        	}
        }
    	return res;
    }
};

//brute force, O((mn)^2)
//TLE
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        int res = INT_MIN;    	
        int sum = INT_MIN, maxSum = INT_MIN;
  		for(int i = 0; i < rows; ++i) {
  			for(int j = 0; j < cols; ++j) {
  				if(i > 0) matrix[i][j] += matrix[i-1][j];
  				if(j > 0) matrix[i][j] += matrix[i][j-1];
  				if(i > 0 && j > 0) matrix[i][j] -= matrix[i-1][j-1];

  				for(int ii = 0; ii <= i; ++ii) {
  					for(int jj = 0; jj <= j; ++jj) {
  						sum = matrix[i][j];
  						if(ii > 0) sum -= matrix[ii-1][j];
  						if(jj > 0) sum -= matrix[i][jj-1];
  						if(ii > 0 && jj > 0) sum += matrix[ii-1][jj-1];

  						if(sum == k) return k;
  						if(sum < k) 
  							maxSum = max(maxSum, sum);
  					}
  				}
  			}
  		}
  		return maxSum;
   	}
};
