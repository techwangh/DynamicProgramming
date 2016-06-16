#ifndef COINCHANGE
#define COINCHANGE

#include <vector>
#include <limits.h>

using namespace std;

class CoinChange {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int n = coins.size();
        vector<unsigned int> amounts(amount+1,INT_MAX);
        amounts[0] = 0;
        for(int i = 1; i <= amount; ++i) {
            for(int k = 0; k < n; ++k) {
                if(i >= coins[k] && amounts[i-coins[k]] != INT_MAX) {
                    amounts[i] = min(amounts[i], amounts[i-coins[k]]+1);
                }
            }
        }

        return amounts[amount] == INT_MAX ? -1 : amounts[amount];

    }

    void test() {
        vector<int> coins{1,2,5};
        int amount = 10;
        cout << coinChange(coins,amount) << endl;
    }
};

#endif // COINCHANGE

