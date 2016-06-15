#ifndef COUNTNUMBERSWITHUNIQUEDIGITS
#define COUNTNUMBERSWITHUNIQUEDIGITS

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> count(n+1,0);
        count[0] = 1;
        if(n >= 1) count[1] = 10;
        for(int i = 2; i <= n; ++i) {
            int sum = 9;
            int k = 9;
            while(k > 10-i) {
                sum *= k;
                --k;
            }
            count[i] = sum + count[i-1];
        }
        return count[n];
    }
};

#endif // COUNTNUMBERSWITHUNIQUEDIGITS

