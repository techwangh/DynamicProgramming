#ifndef COUNTINGBITS
#define COUNTINGBITS

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> count(num+1);
        count[0] = 0;

        int times = 0;
        if(num > 0) {
            times = log2(num);
            count[1] = 1;
        }

        for(int i = 1; i < times; ++i) {
            int begin = pow(2,i);
            int end = pow(2,i+1);
            for(int k = begin; k != end; ++k) {
                count[k] = count[k-begin] + 1;
            }
        }
        int begin = pow(2,times);
        for(int i = begin; i <= num; ++i) {
            count[i] = count[i - begin] + 1;
        }
        return count;
    }
};

#endif // COUNTINGBITS

