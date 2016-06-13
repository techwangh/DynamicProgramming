#ifndef EXAMPLSOFBOOK
#define EXAMPLSOFBOOK

#include <iostream>
#include <vector>
#include <climits>	//INT_MAX

using namespace std;


void cutRod(vector<int>& p,int n) {
    vector<int> r(n+1,0);
    vector<int> s(n+1,0);
    int q;

    for(int i = 1; i <= n; ++i) {
        for(int k = 1; k <= i; ++k) {
            q = p[k-1] + r[i-k];
            if(r[i] < q) {
                r[i] = q;
                s[i] = k;
            }
        }
    }
    while(n>0) {
        cout << s[n] << " ";
        n = n - s[n];
    }

}


void printMatrixChainOrder(vector<vector<int>>& s, int i, int j) {
    int k = s[i][j];
    if(i == j) {
        cout << i;
    }
    else {
        cout << "(";
        printMatrixChainOrder(s,i,k);
        printMatrixChainOrder(s,k+1,j);
        cout << ")";
    }
}


void matrixChainOrder(vector<int>& p) {
    int n = p.size()-1;
    vector<vector<int>> r(n+1,vector<int>(n+1,INT_MAX));
    vector<vector<int>> s(n+1,vector<int>(n+1,0));

    for(int i = 1; i <= n; ++i) {
        r[i][i] = 0;
    }

    for(int l = 2; l <= n; ++l) {
        for(int i = 1; i <= n-l+1;++i) {
            int j = i+l-1;
            for(int k = i; k != j; ++k) {
                int q = r[i][k] + r[k+1][j] + p[i-1]*p[k]*p[j];
                if(r[i][j] > q) {
                    r[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    printMatrixChainOrder(s,1,n);
}


void printLongestIncresingSequence(vector<int>& p, vector<int>& r, int maxLength, int indexOfMax) {
    if(maxLength == 1) {
        cout << p[indexOfMax] << " ";
    }else {
        int i = indexOfMax;
        while(r[i] != maxLength-1) {
            --i;
        }
        printLongestIncresingSequence(p,r,maxLength-1,i);
        cout << p[indexOfMax] << " ";
    }
}


void longestIncresingSequence1(vector<int>& p) {     //O(n^2)
    int n = p.size();
    vector<int> r(n,1);     //store the length of longest increasing sequence of p[0..i]
    for(int i = 1; i != n; ++i) {
        for(int k = 0; k != i; ++k) {
            if(p[i] > p[k]) {
                if(r[i] < r[k] + 1) {
                    r[i] = r[k] + 1;
                }
            }
        }
    }

    int maxLength = 0 ;
    int indexOfMax;
    for(int i = 0; i != n; ++i) {
        if(maxLength < r[i]) {
            maxLength = r[i];
            indexOfMax = i;
        }
    }
    printLongestIncresingSequence(p,r,maxLength,indexOfMax);
    cout << endl;
}


void longestIncresingSequence2(vector<int> &p) {    //O(nlogn)
    int n = p.size();
    vector<int> incSequence,incSequence1;
    incSequence.push_back(p[0]);    //ultimate longest increasing sequence
    incSequence1.push_back(p[0]);   //temp increasing sequence

    for(int i = 1; i!= n; ++i) {
        if(p[i] > incSequence1.back()) {
            incSequence1.push_back(p[i]);
            incSequence = incSequence1;
        }else if(p[i] <= incSequence1.front()) {
            incSequence1.front() = p[i];
        }else {                         //二分法
            int begin = 0;
            int end = incSequence1.size()-1;
            while(begin + 1 != end) {
                int mid = (begin + end)/2;
                if(p[i] < p[mid]) {
                    end = mid;
                }else {
                    begin = mid;
                }
            }
            incSequence1[end] = p[i];
        }
    }

    vector<int>::const_iterator it = incSequence.begin();
    while(it != incSequence.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

}


template <typename T>
void printLongestCommonSubsequence(vector<T> &p1, vector<T> &p2, vector<vector<int>>& r, int i, int j);


template <typename T>
void longestCommonSubsequence(vector<T>& p1, vector<T>& p2) {
    int m = p1.size();
    int n = p2.size();
    vector<vector<int>> r(m+1,vector<int>(n+1,0));    //store the length of longest common subsequence of p1[] and p2[]

    for(int i = 0; i != m; ++i) {
        for(int j = 0; j != n; ++j) {
            if(p1[i] == p2[j]) {
                r[i+1][j+1] = r[i][j] + 1;
            }else if(r[i+1][j] > r[i][j+1]) {
                r[i+1][j+1] = r[i+1][j];
            }else {
                r[i+1][j+1] = r[i][j+1];
            }
        }
    }
    printLongestCommonSubsequence(p1,p2,r,m,n);
    cout << endl;
}


//注意这里的判断顺序与上面设置的时候的判断顺序相反，需仔细思考
//嫌麻烦可以直接像p224中那样设置一个b表示回溯的路径
template <typename T>
void printLongestCommonSubsequence(vector<T>& p1, vector<T>& p2, vector<vector<int>>& r, int i, int j) {
    if(i == 0 || j == 0) {
        return;
    }
    if(r[i][j] == r[i-1][j]) {
        printLongestCommonSubsequence(p1,p2,r,i-1,j);
    }else if(r[i][j] == r[i][j-1]) {
        printLongestCommonSubsequence(p1,p2,r,i,j-1);
    }else {
        printLongestCommonSubsequence(p1,p2,r,i-1,j-1);
        cout << p1[i-1] << " ";
    }
}

#endif // EXAMPLSOFBOOK

