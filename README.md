# Algorithms-Class-Quizz

# House Robber – Algorithms Quiz 6

**Author:** Nick Siguencia  
**Course:** Algorithms  
**Language:** C++

---

# Description
LeetCode-style solution to the House Robber problem.  
Given an array `nums` representing money in each house, find the maximum amount that can be robbed without robbing two adjacent houses.

---

# Approach
Uses Dynamic Programming with space optimization:

- `take = prev2 + nums[i]`  
- `skip = prev1`  
- `current = max(take, skip)`

Only stores three variables → O(1) space, O(n) time.

---

# Code

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int prev2 = 0, prev1 = 0, current = 0;
        for (int money : nums) {
            int take = prev2 + money;
            int skip = prev1;
            current = max(take, skip);
            prev2 = prev1;
            prev1 = current;
        }
        return current;
    }
};
