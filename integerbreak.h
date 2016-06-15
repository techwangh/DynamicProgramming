#ifndef INTEGERBREAK
#define INTEGERBREAK

class Solution {
public:
    int integerBreak(int n) {
        vector<int> maxProducts(n+1,0);
        maxProducts[1] = 1;
        for(int i = 2; i <= n; ++i) {
            for(int k = 1; k != i; ++k) {
                maxProducts[i-k] = max(maxProducts[i-k],i-k);
                maxProducts[i] = max(maxProducts[i],maxProducts[i-k]*k);
            }
        }
        return maxProducts[n];
    }
};

#endif // INTEGERBREAK

