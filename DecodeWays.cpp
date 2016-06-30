
//recursion, slow
class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0) {
            return 0;
        }

        int res = 0;
        decode(s, 0, res);
        return res;
    }

    void decode(string &s, int start, int &res) {
    	if(start == s.size()) {
    		++res;
    		return;
    	}
    	if(s[start] != '0') {
    		decode(s, start+1, res);
    	}else {
    		return;
    	}
        
        if(start+1 < s.size() && (s[start] == '1' || (s[start] == '2' && s[start+1] < '7')))
            decode(s, start+2, res);
            
        
    	
    }
};

//Dynamic Programming, faster
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        vector<int> dp(s.size()+1,1);

        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '0') dp[i+1] = 0;
            else dp[i+1] = dp[i];
            if(i >= 1 && (s[i-1] == '1' || (s[i-1] == '2' && s[i] < '7')))
                dp[i+1] += dp[i-1];
        }

        return dp.back();
    }
};