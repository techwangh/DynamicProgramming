class Solution {
public:
    int longestValidParentheses(string s) {
    	vector<int> length(s.size(), 0);
    	int res = 0;
    	for(int i = 1; i < s.size(); ++i) {
    		if(s[i] == ')' && i-length[i-1]-1 >=0 && s[i-length[i-1]-1] == '(') {
    			length[i] = length[i-1] + 2 + (i-length[i-1]-2 >= 0 ? length[i-length[i-1]-2] : 0);
    			res = max(res, length[i]);
    		}
    	}
    	return res;
    }
};
