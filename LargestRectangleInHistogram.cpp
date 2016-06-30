//brute force
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    	if(heights.size() == 0) return 0;

    	int maxArea = 0;
    	for(int i = 0; i < heights.size(); ++i) {
    		int minVal = heights[i];
    		for(int j = i; j < heights.size(); ++j) {
    			minVal = min(minVal, heights[j]);
    			
    			maxArea = max(maxArea, minVal * (j-i+1));
    		}
    	}
    	return maxArea; 
    }
};


//better solution
class Solution {
public :
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