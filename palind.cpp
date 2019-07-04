#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

bool IsPalin(const char *str, int n) {
  if (str == NULL || n <= 0) {
    return false;
  }
  int head = 0;
  int tail = n - 1;

  while (head <= tail) {
    if (str[head] == str[tail]) {
      head++;
      tail--;
    } else {
      cout <<  str[head] << " not equal " << str[tail] << endl;
      return false;
    }
  }
  return true;
}
bool IsPalinMinddle(const char *str, int n) {
  if (str == NULL || n <= 0) {
    return false;
  }

  int first = 0;
  int second = 0;

  if (n % 2 == 0) {
    first = n / 2 - 1;
    second = first + 1;
  } else {
    first = second = n / 2;
  }

  while (first >= 0 && second < n) {
    if (str[first] == str[second]) {
      first--;
      second++;
    } else {
      cout <<  str[first] << " not equal " << str[second] << endl;
      return false;
    }
  }
  return true;
}

int main() {
  char str [] = {'a', 'b', 'a', 'c', 'd', 'e', 0};
  //char str [] = {'a', 0};
  //char str [] = {'a', 'b', 'c', 'c', 'b', 'a', 0};

  int n = strlen(str);
  bool str_test = IsPalinMinddle(str, n);
  if (str_test) {
    cout << str << " is Palin" << endl;
  } else {
    cout << str << " is not Palin" << endl;
  }

  return 0;
}
