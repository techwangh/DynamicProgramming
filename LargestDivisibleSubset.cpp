class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> prevIndex(nums.size());
        vector<int> length(nums.size(), 1);
        vector<int> res;
        int maxIndex = 0, maxLength = 0;

        for(int i = 0; i < nums.size(); ++i) {
        	prevIndex[i] = i;
        }

        for(int i = 1; i < nums.size(); ++i) {
        	for(int j = 0; j < i; ++j) {
        		if(nums[i]%nums[j] == 0 && length[i] < length[j]+1) {
        			length[i] = length[j]+1;
        			prevIndex[i] = j;
        		}
        	}
        	if(maxLength < length[i]) {
        		maxLength = length[i];
        		maxIndex = i;
        	}
        }

        res.resize(maxLength);
        maxLength--;
        while(prevIndex[maxIndex] != maxIndex) {
        	res[maxLength] = nums[maxIndex];
        	maxLength--;
        	maxIndex = prevIndex[maxIndex];
        }
        res[maxLength] = nums[maxIndex];
        return res;
    }
};