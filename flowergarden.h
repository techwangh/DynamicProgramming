#ifndef FLOWERGARDEN
#define FLOWERGARDEN

#include <iostream>
#include <vector>
#include <map>

template <typename T>
void printVec(const vector<T>& vec);

#define REP(i,n) for(int i=0;i<(n);++i)
template<class T> inline int size(const T&c) { return c.size(); }

class FlowerGarden{

public:
    bool isCross(const vector<int>& bloom, const vector<int>& wilt, int i, int j) {
        if(wilt[i] < bloom[j] || wilt[j] < bloom[i]) {
            return false;
        }else {
            return true;
        }
    }

    void insertIntoOrder(vector<int>& order, const vector<int>& height, int i, int k) {
        int j;
        for(j = i-1; j >= k; --j) {
            order[j+1] = order[j];
        }
        order[j+1] = height[i];
    }

//    vector<int> getOrdering(const vector<int>& height, const vector<int>& bloom, const vector<int>& wilt) {
//        int n = height.size();
//        map<int,int> height_index;
//        for(int i = 0; i != n; ++i) {
//            height_index[height[i]] = i;
//        }

//        vector<int> order(n,0);
//        order[0] = height[0];
//        for(int i = 1; i != n; ++i) {
//            for(int k = 0; k != i; ++k) {
//                int index = height_index[order[k]];

//                if(!isCross(bloom,wilt,i,index)) {
//                    if(height[i] > height[index]) {
//                        insertIntoOrder(order,height,i,k);
//                        break;
//                    }else if(k == i-1){
//                        order[i] = height[i];

//                    }else {
//                        continue;
//                    }

//                }else {
//                    if(height[i] < height[index]) {
//                        insertIntoOrder(order,height,i,k);
//                        break;
//                    }else if(k == i-1){
//                        order[i] = height[i];
//                    }else {
//                        continue;
//                    }
//                }
//            }
//        }

//        return order;
//    }


    vector <int> getOrdering(vector <int> height, vector <int> bloom, vector <int> wilt) {
      int n = size(height);
      vector<bool> done(n,false);
      vector<int> res(n);
      REP(i,n) {
        int best = -1;
        REP(j,n) if(!done[j]) {
          bool ok = true;
          REP(k,n)
            if(k!=j && !done[k] && height[k]<height[j] && bloom[k]<=wilt[j] && wilt[k]>=bloom[j])
              ok = false;
          if(ok && (best==-1 || height[j]>height[best])) best=j;
        }
        res[i] = height[best];
        done[best] = true;
      }
      return res;
    }

    void test() {
        vector<vector<int>> height{{5,4,3,2,1},
                                    {5,4,3,2,1},
                                    {5,4,3,2,1},
                                    {5,4,3,2,1},
                                    {1,2,3,4,5,6},
                                    {3,2,5,4}};
        vector<vector<int>> bloom{{1,1,1,1,1},
                                   {1,5,10,15,20},
                                   {1,5,10,15,20},
                                   {1,5,10,15,20},
                                   {1,3,1,3,1,3},
                                   {1,2,11,10}};
        vector<vector<int>> wilt{{365,365,365,365,365},
                                  {4,9,14,19,24},
                                  {5,10,15,20,25},
                                  {5,10,14,20,25},
                                  {2,4,2,4,2,4},
                                  {4,3,12,13}};
        vector<int> result;

        for(int i = 1; i != 6; ++i) {
            result = getOrdering(height[i],bloom[i],wilt[i]);
            printVec(result);
        }

    }

};

#endif // FLOWERGARDEN

