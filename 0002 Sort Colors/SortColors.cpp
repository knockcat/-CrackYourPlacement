class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        int start = 0, end = n-1;
        int zero = 0;
        
        while(start <= end)
        {
            if(nums[start] == 0)
                swap(nums[zero++], nums[start++]);
            else if(nums[start] == 2)
                swap(nums[start], nums[end--]);
            else
                ++start;
        }
        
    }
};
