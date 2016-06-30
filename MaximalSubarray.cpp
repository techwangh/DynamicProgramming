class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	if(nums.size() == 0) return 0;
        int res, tmp;
        res = tmp = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
        	tmp = max(tmp + nums[i], nums[i]);
        	res = max(res, tmp);	//res是nums[0..i-1]的最大值，tmp是包含nums[i]的最大值，nums[0..i]的最大值一定在这两个中产生
        }

        return res;
    }
};

//divide and conquer
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	return getMaxSubarray(nums, 0, nums.size()-1);

 	}  

 	int getMaxSubarray(vector<int>& nums, int left; int right) {
 		if(left >= right) return nums[left];
 		int mid = (left + right)/2;
 		int leftMax = getMaxSubarray(nums, left, mid);
 		int rightMax = getMaxSubarray(nums, mid+1,right);
 		int sum = 0;
 		int midMax = nums[mid];
 		for(int i = mid; i >= left; --i) {
 			sum += nums[i];
 			midMax = max(midMax, sum);
 		}
 		sum = midMax;
 		for(int i = mid+1; i <= right; ++i) {
 			sum += nums[i];
 			midMax = max(midMax, sum);
 		}
 		return max(midMax, max(leftMax, rightMax));
 	} 	
};