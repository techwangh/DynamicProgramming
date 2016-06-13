#ifndef ZIGZAG
#define ZIGZAG

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printVec(const vector<T>& vec) {
    vector<int>::const_iterator it = vec.begin();
    while(it != vec.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}


int longestZigZag(vector<int>& vec) {
    vector<int> differences;
    vector<int>::const_iterator it = vec.begin();
    while((it+1) != vec.end()) {
        differences.push_back(*(it+1) - *it);
        ++it;
    }

    int n = differences.size();
    vector<int> optimal(n,0);
    optimal[0] = 1;
    for(int i = 1; i <= n; ++i) {
        //solution 1
//        if(differences[i]*differences[i-1] < 0) {     //{ 70, 55, 13, 2, 99, 2, 80, 80,
                                                        //  80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 } wrong in this case
//            optimal[i] = optimal[i-1] + 1;
//        }else {
//            optimal[i] = optimal[i-1];
//        }
        //solution 2
        for(int k = 0; k != i; ++k) {
            if((differences[i]*differences[k] < 0) && (optimal[i] < optimal[k]+1)) {
                optimal[i] = optimal[k]+1;
            }
        }
    }
    printVec(differences);
    printVec(optimal);
    int max = 0;
    it = optimal.begin();
    while(it != optimal.end()) {
        if(*it > max)
            max = *it;
        ++it;
    }
//    cout << "length of longest subsequence:" << optimal[n-1]+1 << endl;
    return max+1;
}


//better answer
class ZigZag {
  public:
  int longestZigZag(vector <int> sequence)
  {
    if(sequence.size() == 1) return 1;
    vector<int> v(sequence.size()-1);
    for(int i=1;i<sequence.size();i++)
    {
      v[i-1] = sequence[i] - sequence[i-1];
    }
    //    dir is first nonzero
    int ii=0;
    while( ii < v.size() && v[ii] == 0)
    ii++;
    if(ii == v.size()) return 1;
    int dir = v[ii];
    int len = 2;
    for(int i=ii+1;i<v.size();i++)
    {
      if(v[i] * dir < 0)
      {
        dir *= -1;
        len++;
      }
    }
    return len;
  }
};


#endif // ZIGZAG

