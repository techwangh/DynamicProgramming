#ifndef FLOWERGARDEN
#define FLOWERGARDEN

#include <iostream>
#include <vector>

class FlowerGarden{

public:
    bool isCross(vector<int>& bloom, vector<int>& wilt, int i, int j) {
        if(wilt[i] < bloom[j] || wilt[j] < bloom[i]) {
            return false;
        }else {
            return true;
        }
    }

    void insertIntoOrder(vector<int>& order, vector<int>& height, int i, int k) {
        int j;
        for(j = i-1; j >= k; --j) {
            order[j+1] = order[j];
        }
        order[j] = height[i];
    }

    vector<int>& getOrdering(vector<int>& height, vector<int>& bloom, vector<int>& wilt) {
        int n = height.size();
        vector<int> order(n,0);
        order[0] = height[0];
        for(int i = 1; i != n; ++i) {
            for(int k = 0; k != i; ++k) {
                if(!isCross(bloom,wilt,i,k)) {
                    if(height[i] > height[k]) {
                        insertIntoOrder(order,height,i,k);
                        break;
                    }else {
                        continue;
                    }
                }else {
                    if(height[i] < height[k]) {
                        insertIntoOrder(order,height,i,k);
                        break;
                    }else {
                        continue;
                    }
                }
            }
        }

        return order;
    }

};

#endif // FLOWERGARDEN

