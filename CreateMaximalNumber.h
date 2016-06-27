#include <vector>
#include <algorithm>

template <typename T>
void printVec(const vector<T>& vec);

class CreateMaximalNumber {

public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> res;

        for(int i = 0; i <= min(m,k); ++i) {
            if(k-i <= n) {
                res = max(res, merge(extractNums(nums1, i), extractNums(nums2,k-i)));
            }else {
                continue;
            }
        }

        return res;
    }

    vector<int> extractNums(vector<int>& nums, int n) {
        vector<int> res;
        pair<int, int> val_index;
        int p = 0, r = nums.size()-n;
        while(n != 0) {
            --n;
            val_index = extractNum(nums,p,r);
            res.push_back(val_index.first);
            p = val_index.second+1;
            r += 1;
        }

        return res;
    }

    pair<int,int> extractNum(vector<int>& nums, int p, int r) {
        int maxValIndex = p;
        int maxVal = nums[p];
        for(int i = p+1; i <= r; ++i) {
            if(maxVal < nums[i]) {
                maxVal = nums[i];
                maxValIndex = i;
            }

        }
        return make_pair(maxVal, maxValIndex);
    }

    vector<int> merge(vector<int> nums1, vector<int> nums2) {
        vector<int> res;
        while(nums1.size() + nums2.size()) {
            vector<int>& maxVec = nums1>nums2 ? nums1 : nums2;
            res.push_back(maxVec[0]);
            maxVec.erase(maxVec.begin());
        }
        return res;
    }

    void test() {
        vector<int> nums1{3,4,6,5};
        vector<int> nums2{9,1,2,5,8,3};
        int k = 5;
        printVec(maxNumber(nums1,nums2,k));
    }
};

//another solution of extracting numbers
//see:http://www.cnblogs.com/grandyang/p/5136749.html
vetor<int> extractNums(vector<int>& nums, int k) {
    vector<int> res;
    int drop = nums.size() - k;
    for(int num : nums) {
        while(drop && res.size() && res.back() < num) {
            res.pop_back();
            --drop;
        }
        res.push_back(num);
    }
    res.resize(k);
    return res;

}
