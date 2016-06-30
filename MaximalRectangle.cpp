class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
    	if(matrix.size() == 0) return 0;
        vector<int> heights(matrix[0].size(), 0);
        int  res = 0;

        for(int i = 0; i < matrix.size(); ++i) {
        	for(int j = 0; j< matrix[0].size(); ++j) {
        		heights[j] = matrix[i][j] == '0' ? 0 : heights[j]+1;
        	}
        	res = max(res, largestRectangleArea(heights));
        }

        return res;
    }

    int largestRectangleArea(vector<int>& heights) {
    	int res = 0;
    	stack<int> s;
        heights.push_back(0);

        for(int i =  0; i < heights.size(); ++i) {
            while(!s.empty() && heights[i] < heights[s.top()]) {
                int cur = s.top();
                s.pop();
                res = max(res, heights[cur]*(s.empty() ? i : i-s.top()-1));     //i-s.top()-1  !!!
            }
            s.push(i);
        }
        return res;
    }
};