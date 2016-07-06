class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> str;
        partitionDFS(s, res, str, 0);
        return res;
    }

    void partitionDFS(string& s, vector<vector<string>>& res, vector<string>& str, int start) {
    	if(start == s.size()) {
    		res.push_back(str);
    		return;
    	}
    	for(int i = start; i < s.size(); ++i) {
    		if(isPalindrome(s, start, i)) {
    			str.push_back(s.substr(start, i-start+1));
    			partitionDFS(s, res, str, i+1);
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