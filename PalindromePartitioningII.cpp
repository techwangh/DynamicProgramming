//use palindrome partition I and TLE, no surprise
class Solution {
public:
    int minCut(string s) {
        vector<vector<string>> res;
        vector<string> str;
        int minVal = INT_MAX;
        partitionDFS(s, res, str, 0, minVal);
        return minVal;
    }

    void partitionDFS(string& s, vector<vector<string>>& res, vector<string>& str, int start, int& minVal) {
    	if(start == s.size()) {
    		res.push_back(str);
    		int cutTimes = str.size()-1;
    		minVal = min(minVal, cutTimes);
    		return;
    	}
    	for(int i = start; i < s.size(); ++i) {
    		if(isPalindrome(s, start, i)) {
    			str.push_back(s.substr(start, i-start+1));
    			partitionDFS(s, res, str, i+1, minVal);
    			str.pop_back();
    		}
    	}
    }

    bool isPalindrome(string& s, int start, int end) {
    	while(start < end) {
    		if(s[start] != s[end]) return false;
    		++start;
    		--end;
    	}
    	return true;
    }    
};

//DP
class Solution {
public:
    int minCut(string s) {
        vector<int> dp(s.size()+1, INT_MAX);    //mincut of s[0..i]
        vector<vector<bool>> isPalindrome(s.size(), vector<bool>(s.size(), false));

        dp[0] = -1;
        for(int i = 1; i <= s.size(); ++i) {
            for(int j = i; j >= 1; --j) {
                if(s[i-1] == s[j-1] && (i-j <= 2 || isPalindrome[j][i-2])) {
                    isPalindrome[j-1][i-1] = true;
                    dp[i] = min(dp[i], dp[j-1] + 1);
                }
            }
        }
        return dp[s.size()];
    }
};
