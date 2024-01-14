// ref. https://leetcode.com/problems/contains-duplicate/

// below solution is O(N^2)
// class Solution {
// public:
//   bool containsDuplicate(vector<int>& nums) {
//     int last
//     for (int i = 0; i < nums.size() - 1; i++) {
//       for (int j = i + 1; j < nums.size)
//     }
//     return false;
//   }
// };

// use hash map has key value
class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> map;
    for (int num : nums) {
        if (map[num] >= 1)
            return true;
        map[num]++;
    }
    return false;
  }
};
