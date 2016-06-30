#include <iostream>
#include "ExamplesOnBook_CLRS.h"
#include "BadNeighbors.h"
#include "FlowerGarden.h"
#include "RussiandollEnvelopes.h"
#include "CoinChange.h"
#include "MaximalSquare.h"
#include "CreateMaximalNumber.h"

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


void quickSort(vector<int>& nums, int p, int r) {


    if(p < r) {
        int pivot = nums[p];
        int i = 0, j = p;
        for(i = p+1; i <= r; ++i) {
            if(nums[i] < pivot) {
                swap(nums[i], nums[j]);
                ++j;
            }
            swap(nums[j] , pivot);
        }

        quickSort(nums, p, j-1);
        quickSort(nums, j+1, r);
    }
}


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

  vector<TreeNode*> *generateTreesDFS(int start, int end) {
      vector<TreeNode*> *subTree = new vector<TreeNode*>();
      if(start > end) {
          subTree->push_back(NULL);
      }else {
          for(int i = start; i <= end; ++i) {
              vector<TreeNode*> *leftSubTree = generateTreesDFS(start, i-1);
              vector<TreeNode*> *rightSubTree = generateTreesDFS(i+1, end);
              for(int j = 0; j < leftSubTree->size(); ++j) {
                  for(int k = 0; k < rightSubTree->size(); ++k) {
                      TreeNode *node = new TreeNode(i);
                      node->left = (*leftSubTree)[j];
                      node->right = (*rightSubTree)[k];
                      subTree->push_back(node);
                  }
              }
          }

      }
      return subTree;
  }

vector<TreeNode*> generateTrees(int n) {
    return *generateTreesDFS(1, n);
}



void test() {
    vector<TreeNode*> node = generateTrees(0);

    cout << node[0] << endl;
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

    test();

    return 0;
}

