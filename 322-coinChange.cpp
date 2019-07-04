#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int coinChange(vector<int>& coins, int amount) {
      int n = coins.size();
      vector<int> min_count(amount+1, -1);
      min_count[0] = 0;
      for (int i = 1; i <= amount; ++i) {
        int min_value = -1;
        int init = false;
        for (int j = 0; j < n; ++j) {
          int position = i - coins[j];
          if (position >= 0 && min_count[position] != -1) {
            int temp_value = min_count[position] + 1;
            if (!init || temp_value < min_value) {
              min_value = temp_value;
              init = true;
            }
          }
        }
        min_count[i] = min_value;
      }
      return min_count[amount];
    }
};

int main() {
  vector<int> coins;
  coins.push_back(2);
  int amount = 3;

  Solution s;
  int ret = s.coinChange(coins, amount);
  cout << "ret:" << ret << endl;

  return 0;
}
