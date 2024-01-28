// ref. https://leetcode.com/problems/group-anagrams/
// ref. https://leetcode.com/problems/group-anagrams/solutions/3687735/beats-100-c-java-python-beginner-friendly

#include <algorithm>
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> map;
    for (string str : strs) {
      string sortedStr = str;
      std::sort(sortedStr.begin(), sortedStr.end());
      map[sortedStr].push_back(str);
    }

    vector<vector<string>> res;
    for (auto& pair : map) {
      res.push_back(pair.second);
    }

    return res;
  }
};
