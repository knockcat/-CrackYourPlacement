class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size(), start = 1;
        
        for(int i = 1; i < n; ++i)
        {
            if(nums[i] == nums[start-1])   
                continue;
            else
            {
                nums[start] = nums[i];
                ++start;
            }
        }
        
        return start;
    }
};
