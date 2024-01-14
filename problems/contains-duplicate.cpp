// ref. https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < nums.size(); j++) {
        if (j == i || nums[i] != nums[j]) continue;
        return true;
      }
    }
    return false;
  }
};
