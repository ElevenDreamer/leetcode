#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int minimumTotal(vector<vector<int> >& triangle) {
      int min_total = 0;
      int n = triangle.size();
      vector<vector<int> > state_np;
      vector<int> first_row = triangle[0];
      state_np.push_back(first_row);
      for (int i = 1; i < n; ++i) {
        vector<int> triangle_row = triangle[i];
        int size = triangle_row.size();
        vector<int> state_np_row(size, 0);
        state_np.push_back(state_np_row);
        for (int j = 0; j < size; ++j) {
          int item = triangle_row[j];
          int temp_min_value = 0;
          bool do_copy = false;
          if (j - 1 >= 0) {
            temp_min_value = state_np[i-1][j-1] + item;
            do_copy = true;
          }
          if (j < size - 1) {
            int temp = state_np[i-1][j] + item;  
            if (temp < temp_min_value || !do_copy) {
              temp_min_value = temp;
            }
          }
          state_np[i][j] = temp_min_value;
        }
      }
      vector<int> last_row = state_np[n-1];
      min_total = last_row[0];
      for (int i = 1; i < last_row.size(); ++i) {
        if (last_row[i] < min_total) {
          min_total = last_row[i];
        }
      }
      return min_total;
    }
    int minimumTotal2(vector<vector<int> >& triangle) {
      int min_total = 0;
      int n = triangle.size();
      vector<int> state_np(n*(n+1)/2, 0);
      state_np[0] = triangle[0][0];
      for (int i = 1; i < n; ++i) {
        vector<int> triangle_row = triangle[i];
        int size = triangle_row.size();
        for (int j = 0; j < size; ++j) {
          int item = triangle_row[j];
          int temp_min_value = 0;
          bool do_copy = false;
          if (j - 1 >= 0) {
            int position_up = i * (i-1) / 2 + (j - 1);
            temp_min_value = state_np[position_up] + item;
            do_copy = true;
          }
          if (j < size - 1) {
            int position_up_1 = i * (i-1) / 2 + j;
            int temp = state_np[position_up_1] + item;  
            if (temp < temp_min_value || !do_copy) {
              temp_min_value = temp;
            }
          }
          state_np[i*(i+1)/2 + j] = temp_min_value;
        }
      }
      int i = n * (n - 1) / 2;
      min_total = state_np[i];
      for (; i < n * ( n + 1) / 2; ++i) {
        if (state_np[i] < min_total) {
          min_total = state_np[i];
        }
      }
      return min_total;
    }
    int minimumTotalBest(vector<vector<int> >& triangle) {
      int n = triangle.size();
      vector<int> state_np(n+1, 0);
      for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
          state_np[j] = std::min(state_np[j], state_np[j+1]) + triangle[i][j];
        }
      }
      return state_np[0];
    } 
};

int main() {
  vector<vector<int> > triangle; 
  vector<int> v1;
  v1.push_back(2);
  triangle.push_back(v1);
  vector<int> v2;
  v2.push_back(3);
  v2.push_back(4);
  triangle.push_back(v2);
  vector<int> v3;
  v3.push_back(6);
  v3.push_back(5);
  v3.push_back(7);
  triangle.push_back(v3);
  vector<int> v4;
  v4.push_back(4);
  v4.push_back(1);
  v4.push_back(8);
  v4.push_back(3);
  triangle.push_back(v4);

  Solution s;
  int min_total = s.minimumTotalBest(triangle);
  cout << "min_total:" << min_total << endl;

  return 0;
}
