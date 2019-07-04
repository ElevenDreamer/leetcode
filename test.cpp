#include <iostream>

bool is_alpha(char c) {

}
int max_value(string str) {
  int max_value = 0;
  // find . sub str
  // str 

  return max_value;
}


int max_digital_value(string str) {
  if (str.size() == 0)
    return 0;
  int max_value = -1;
  int first_position = 0;
  iterator start= it.begin();
  iterator stop = it.begin();
  bool is_cal_max_value = false;
  for (; stop != str.end(); ++stop) {
    if (is_alpha(*start)) {
      start++;
      continue;
    }
    if (*stop == '.') {
      if (first_position == 0) {
        first_position == 1;
        continue;
      } else {
        is_cal_max_value = true;
      }
    }
    if (is_alpha(*stop)) {
      is_cal_max_value = true;
    }
    if (is_cal_max_value) {
        string sub_str(str, start, stop);
        int value = max_value(str);
        if (value > max_value) {
          max_value = value;
        }
        size_t position = sub_str.find_first_of('.', 0);
        if (position != string::npos) {
          start += position;
        } else {
          start = stop;
        }
        first_postion = 0;
        is_cal_max_value = false;
    }
  }
  if (start != str.end()) {
    string sub_str(str, start, stop);
    int value = max_value(str);
    if (value > max_value) {
      max_value = value;
    }
  }

  return max_value;
}
