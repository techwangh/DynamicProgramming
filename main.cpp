#include <iostream>
#include "examplsofbook.h"
#include "badneighbors.h"
#include "flowergarden.h"

using namespace std;

template <typename T>
void printVec(const vector<T>& vec) {
    typename vector<T>::const_iterator it = vec.begin();
    while(it != vec.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}

int main() {

#if 0
    //cutRod
    vector<int> p{1,5,8,9,10,17,17,20,24,30};
    for(int i = 1; i <= 10; ++i) {
        cout << "length:" << i << ":";
        cutRod(p,i);
        cout << endl;
    }
#endif

#if 0
    //matrix chain order
    vector<int> p1{30,35,15,5,10,20,25};
    matrixChainOrder(p1);
#endif

#if 0
    //longest increasing sequence
    vector<int> p2{1,2,3,10,4,10,11};
    longestIncresingSequence1(p2);
    longestIncresingSequence2(p2);
#endif


    vector<int> height{5,4,3,2,1};
    vector<int> bloom{1,1,1,1,1};
    vector<int> wilt{365,365,365,365,365};
    vector<int> order(5,0);

    FlowerGarden fl;
    order = fl.getOrdering(height,bloom,wilt);
    printVec(order);

    return 0;
}

