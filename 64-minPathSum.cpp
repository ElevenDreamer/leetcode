#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution {
  public:
    int minPathSum(vector<vector<int> >& grid) {
      int m  = grid.size();
      int n = grid[0].size();
      vector<vector<int> > state_mem(m, vector<int>(n, 0));
      int min_value = minDist(grid,  state_mem, m - 1, n - 1);
      return min_value;
    }
    int minDist(vector<vector<int> >& grid, vector<vector<int> >& state_mem, int i, int j) {
      if (i == 0 && j == 0) return grid[0][0];
      if (state_mem[i][j] > 0) return state_mem[i][j];
      int min_value_up = INT_MAX; 
      if (i - 1 >= 0) {
        min_value_up = minDist(grid, state_mem, i-1, j);
      }
      int min_value_left = INT_MAX;
      if (j - 1 >= 0) {
        min_value_left = minDist(grid, state_mem, i, j-1);
      }
      int min_value = min(min_value_up, min_value_left) + grid[i][j];
      state_mem[i][j] = min_value;
      return min_value;
    }
    int minPathSum1(vector<vector<int> >& grid) {
      int m = grid.size();
      int n = grid[0].size();
      vector<vector<int> > state_mem(m, vector<int>(n, 0));
      int sum_row = 0;
      for (int j = 0; j < n; ++j) {
        sum_row += grid[0][j];
        state_mem[0][j] = sum_row;
      }
      int sum_col = 0;
      for (int i = 0; i < m; ++i) {
        sum_col += grid[i][0];
        state_mem[i][0] = sum_col;
      }
      for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
          state_mem[i][j] = min(state_mem[i][j-1], state_mem[i-1][j]) + grid[i][j];
        }
      }
      return state_mem[m-1][n-1];
    }
};

int main() {
  int m = 3;
  int n = 3;
  vector<vector<int> > grid(m, vector<int>(n, 0));
  grid[0].push_back(1);
  grid[0].push_back(3);
  grid[0].push_back(1);
  grid[1].push_back(1);
  grid[1].push_back(5);
  grid[1].push_back(1);
  grid[2].push_back(4);
  grid[2].push_back(2);
  grid[2].push_back(1);

  Solution s;
  int min_path = s.minPathSum1(grid);
  cout << "min_path:" << min_path << endl;
  return 0;
}
