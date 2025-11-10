class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int prev2 = 0; //max amount of money up to i-2
        int prev1 = 0; //max amount of money up to i-1
        int current = 0; //max money up to current house

        for (int money : nums) 
        {
            int take = prev2 + money;
            int skip = prev1;

            current = max(take, skip); 

            prev2 = prev1;

            prev1 = current;
        }

        return current;
    }
};

//Pushing to Github for Algorithms class. Leetcode style answer for House Robber problem.