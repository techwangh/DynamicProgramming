class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(1,1);
        int i1 = 0, i2 = 0, i3 = 0;
        int v1, v2, v3;
        while(res.size() < n) {
            v1 = res[i1] * 2;
            v2 = res[i2] * 3;
            v3 = res[i3] * 5;
            int minVal = min(v1,min(v2,v3));
            if(minVal == v1) ++i1;;
            if(minVal == v2) ++i2;
            if(minVal == v3) ++i3;
            
            res.push_back(minVal);
        }
        return res.back();
    }
};