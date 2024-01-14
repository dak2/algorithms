#include <string>
#include <algorithm>

class Solution {
public:
    bool isAnagram(string s, string t) {
      if(s.length() != t.length) return false;
      std::sort(s.begin(), s.end());
      std::sort(t.begin(), t.end());
      if (s == t) return true;
      return false;
    }
};
