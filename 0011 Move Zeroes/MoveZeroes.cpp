class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size(), start = 0, i = 0;
        
        while(i < n)
        {
            if(nums[i] != 0)
                swap(nums[i++], nums[start++]);
            else
                ++i;
        }
    }
};
