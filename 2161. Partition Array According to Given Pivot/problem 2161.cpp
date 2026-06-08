class Solution {
public:
  vector<int> pivotArray(vector<int> &nums, int pivot) {
    vector<int> less;
    vector<int> equal;
    vector<int> greater;

    for (int x : nums) {
      if (x < pivot)
        less.push_back(x);
      else if (x == pivot)
        equal.push_back(x);
      else
        greater.push_back(x);
    }

    vector<int> res;
    res.reserve(nums.size());

    for (int x : less)
      res.push_back(x);
    for (int x : equal)
      res.push_back(x);
    for (int x : greater)
      res.push_back(x);

    return res;
  }
};