//DP
class Solution {
public:
    bool isScramble(string s1, string s2) {
    	string str1 = s1;
    	string str2 = s2;
    	sort(str1.begin(), str1.end());
    	sort(str2.begin(), str2.end());
    	if(str1 != str2) return false;

    	int m = s1.size();	
    	vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(m, vector<bool>(m+1, false)));
    	for(int i = 0; i < m; ++i) {
    		for(int j = 0; j < m; ++j) {
    			if(s1[i] == s2[j]) dp[i][j][1] = true;
    		}
    	}
    	for(int len = 2; len <= m; ++len) {
    		for(int i = 0; i <= m-len; ++i) {
    			for(int j = 0; j <= m-len; ++j) {
    				for(int k = 1; k < len; ++k) {
    					if((dp[i][j][k] && dp[i+k][j+k][len-k]) || (dp[i][j+len-k][k] && dp[i+k][j][len-k])) 
    						dp[i][j][len] = true;
    				}
    			}
    		}
    	}
    	return dp[0][0][m];
    }
};

//recursion
class Solution {
public:
    bool isScramble(string s1, string s2) {
    	string str1 = s1;
    	string str2 = s2;
    	sort(str1.begin(), str1.end());
    	sort(str2.begin(), str2.end());
    	if(str1 != str2) return false;

    	if(s1 == s2) return true;
    	int m = s1.size();
    	for(int len = 1; len < m; ++len) {
    		string s11 = s1.substr(0, len);
    		string s12 = s1.substr(len);
    		string s21 = s2.substr(0, len);
    		string s22 = s2.substr(len);
    		if(isScramble(s11, s21) && isScramble(s12, s22)) return true;
    		s21 = s2.substr(m-len);
    		s22 = s2.substr(0, m-len);
    		if(isScramble(s11, s21) && isScramble(s12, s22)) return true;
    	}
    	return false;
    }
};