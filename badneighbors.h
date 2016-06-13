#ifndef BADNEIGHBORS
#define BADNEIGHBORS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BadNeighbors {

public:
    int getMax(vector<int>& donations, int m, int n) {
        int length = n-m+1;
        vector<int> c(length,0);     //c[i]:the value of total donations of donations[0..i] with donations[i] be the last one
        c[0] = donations[m];
        c[1] = donations[m+1];
        //compute c[i]
        for(int i = 2; i != length; ++i) {
            for(int k = 0; k != i-1; ++k) {
                c[i] = max(c[i],c[k]+donations[i+m]);
            }
        }

        //compute largest value
        int maxValue = 0;
        for(int i = 0; i != length; ++i) {
            maxValue = max(maxValue,c[i]);
        }
        return maxValue;
    }

    int maxDonations(vector<int>& donations) {
        int n = donations.size();
        if(n == 2)
            return max(donations[0],donations[1]);
        return max(getMax(donations,0,n-2),getMax(donations,1,n-1));
    }

    void printVec(vector<int>& vec) {
        vector<int>::const_iterator it = vec.begin();
        while(it != vec.end()) {
            cout << *it++ << " ";
//            it++;
        }
        cout << endl;
    }
};


#endif // BADNEIGHBORS

