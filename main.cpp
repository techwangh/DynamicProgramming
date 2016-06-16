#include <iostream>
#include "ExamplesOnBook_CLRS.h"
#include "BadNeighbors.h"
#include "FlowerGarden.h"
#include "RussiandollEnvelopes.h"
#include "CoinChange.h"
#include "MaximalSquare.h"

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


//    lalala
    vector<vector<char>> matrix;
    vector<char> vec{'0'};
    matrix.push_back(vec);
    MaximalSquare ms;
    int a = ms.maximalSquare(matrix);
    cout << a << endl;
    return 0;
}

