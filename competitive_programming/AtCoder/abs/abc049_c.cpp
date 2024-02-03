// ref. https://atcoder.jp/contests/abs/tasks/arc065_a

#include<iostream>
#include<vector>
#include<string>
#include <regex>

using namespace std;

int main() {
  string S;
  cin>> S;

  regex pattern_eraser("eraser");
  regex pattern_erase("erase");
  regex pattern_dreamer("dreamer");
  regex pattern_dream("dream");

  string replaced_str1 = regex_replace(S, pattern_eraser, "");
  string replaced_str2 = regex_replace(replaced_str1, pattern_erase, "");
  string replaced_str3 = regex_replace(replaced_str2, pattern_dreamer, "");
  string replaced_str4 = regex_replace(replaced_str3, pattern_dream, "");

  if(replaced_str4.length() > 0) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}
