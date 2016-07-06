//fastest way
class Solution {
public:
    bool isMatch(string s, string p) {
        int starpos = -1;
        int spos = 0;
        int i = 0, j = 0;
        while(i < s.size()) {
        	if((j < p.size()) && (s[i] == p[j] || p[j] == '?')) {
        		i++; 
        		j++; 
        		continue;
        	}
        	if(j < p.size() && p[j] == '*') {
        		starpos = j++; 
        		spos = i; 
        		continue;
        	}
        	if(starpos != -1) {
        		j = starpos+1; 
        		i = ++spos; 
        		continue;
        	}
        	return false;
        }
        while(p[j] == '*' && j < p.size()) {
        	++j;
        }
        return j == p.size();
    }
};

//recursion, TLE
class Solution {
public:
    bool isMatch(string s, string p) {
  		if(p.empty()) return s.empty();
  		if(p[0] == '*') 
  			return isMatch(s, p.substr(1)) || isMatch(s.substr(1), p);
  		else
  			return !s.empty() && (s[0] == p[0] || p[0] == '?') && isMatch(s.substr(1), p.substr(1));  
    }
};

//DP
class Solution {
public:
    bool isMatch(string s, string p) {
    	int m = s.size();
    	int n = p.size();
    	vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));		//dp[i][j]:if s[0..i-1] matches p[0..j-1]

    	dp[0][0] = true;	//s.empty() && p.empty()

    	for(int j = 1; j <= n; ++j) {
    		dp[0][j] = p[j-1] == '*' && dp[0][j-1];
    	}
    	for(int i = 1; i <= m; ++i) {
    		for(int j = 1; j <= n; ++j) {
    			if(p[j-1] != '*') 
    				dp[i][j] = (s[i-1] == p[j-1] || p[j-1] == '?') && dp[i-1][j-1];
    			else
    				dp[i][j] = dp[i][j-1] || dp[i-1][j];
    		}
    	}
    	return dp[m][n];
    }
};
