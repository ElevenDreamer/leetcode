#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

int maxW = 0;
static bool state[10][101] = {false};

// i:第i个物品, cw: 目前放入的总质量 items:物品总数 n:总的个数 w:最大重量
void max_package(int i, int cw, vector<int> items,int n, int w) {
  cout << "max_package  update maxW  [i=" << i << "]" << "[cw=" << cw << "]" << "[maxW="<< maxW << "]"<< endl;
  if (i == n || cw == w) {
    if (cw > maxW) {
      maxW = cw;
      //cout << "max_package  update maxW  [i=" << i << "]" << "[cw=" << cw << "]" << "[maxW="<< maxW << "]"<< endl;
    }
    return;
  }
  if (state[i][cw]) return;
  state[i][cw] = true;
  max_package(i+1, cw, items, n, w);
  if (cw + items[i] <= w) {
    //cout << "max_package  update cw [i=" << i << "]" << "[item:" << items[i] << "]"<< "[cw=" << cw << "]" << "[maxW="<< maxW << "]"<< endl;
    max_package(i+1, cw + items[i], items, n, w);
  }
} 
int max_package_dp(vector<int> items, int n ,int w) {
  int max_value = 0;
  vector<vector<bool> > state_dp(n, vector<bool>(w+1, false));
  state_dp[0][0] = true;
  state_dp[0][items[0]] = true;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <=w; ++j) {
      if (state_dp[i-1][j]) {
        state_dp[i][j] = state_dp[i-1][j];
      }
    }
    for (int j = 0; j <= w - items[i]; ++j) {
      if (state_dp[i-1][j]) {
        state_dp[i][j+items[i]] = true;
      }
    }
  }

  for (int i = w; i >= 0; --i) {
    if (state_dp[n-1][i]) {
      max_value = i;
      break;
    }
  }
  if (max_value <= 0) return max_value;

  int value = max_value;
  for (int i = n - 1; i > 0; --i) {
    if ((value - items[i]) >= 0 && (state_dp[i-1][value - items[i]] == true)) {
      cout << "route i=" << i << " item:" << items[i] << endl;
      value -= items[i];
    }
  }
  if (value != 0) {
      cout << "route i = 0" <<  " item:" << items[0] << endl;
  }
  return max_value;
}
int max_package_dp_1(vector<int> items, int n, int w) {
  int max_value = 0;
  vector<bool> state_dp(w+1, false);
  state_dp[0] = true;
  state_dp[items[0]] = true;
  for (int i = 1; i < n; ++i) {
    for (int j = w - items[i]; j >= 0; --j) {
      if (state_dp[j]) {
        state_dp[j + items[i]] = true;
      }
    }
  }
  for (int i = w; i >=0; --i) {
    if (state_dp[i]) {
      max_value = i;
      break;
    }
  }
  if (max_value <=0) return max_value;

  int value = max_value;
  for (int i = n-1; i > 0; --i) {
    if (value - items[i] >=0 && state_dp[value - items[i]] == true) {
      cout << "route i=" << i << " item:" << items[i] << endl;
      value -= items[i];
    }
  }
  if (value != 0) {
      cout << "route i=0 " << " item:" << items[0] << endl;
  }
  return max_value;
}

int max_package_value_dp(vector<int> items, vector<int> values, int n, int w) {
  int max_w = 0;
  vector<int> state_dp(w+1, 0);
  state_dp[items[0]] = values[0];

  for (int i = 0; i < n; ++i) {
    for (int j = w - items[i]; j > 0; --j) {
      if (state_dp[j] != 0) {
        int temp_value = state_dp[j] + values[i];
        if (temp_value > state_dp[j + items[i]]) {
          state_dp[j + items[i]] = temp_value;
        }
      }
    }
  }
  for (int i = w; i >= 0; --i) {
    if (state_dp[i] != 0) {
      max_w = i; 
      break;
    }
  }
  cout << "max_w=" << max_w << endl;
  int max_value = -1;
  int position = 0;
  cout << "TEST ------------- TEST" << endl;  
  for (int i = max_w; i >= 0; --i) {
    if (state_dp[i] > max_value) {
      max_value = state_dp[i];
      position = i;
      cout << "max_value:" << max_value << " position:" << i << endl;
    }
  }
  cout << "TEST ------------- TEST END" << endl;  
  cout << "max_value=" << max_value << " position=" << position << endl;
  int value = max_value;
  for (int i = n - 1; i > 0; --i) {
    if (position - items[i] >= 0 && state_dp[position - items[i]] == (value - values[i])) {
        cout << "route i=" << i << " item:" << items[i] << " value:" << values[i] << endl;
        position -= items[i];
        value -= values[i];
    }
  }
  if (value > 0) {
    cout << "route i=0 " << " item:" << items[0] << " value:" << values[0] << endl;
  }
  return max_value;
}

int main()
{
  int n = 10;
  vector<int> items;
  vector<int> values;
  for (int i = 0; i < 10; ++i) {
     items.push_back(rand() % 100);
     values.push_back(rand() % 1000);
     cout << " i= " << i << " item:" << items[i] << " value:" << values[i];
  }
  cout << endl;

  int w = 100;
  /*
  max_package(0, 0, items, 10, 100);
  int max_value = max_package_dp(items, 10, 100);
  cout << "max_value:" << max_value << endl;
  max_value = max_package_dp_1(items, 10, 100);
  cout << "max_value:" << max_value << endl;
  */
  int max_value = max_package_value_dp(items, values, 10, 100);
  cout << "max_value:" << max_value << endl;
  
  return 0;
}
