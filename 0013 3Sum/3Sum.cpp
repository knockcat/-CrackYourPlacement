class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; ++i)
        {
            if(i > 0 and nums[i] == nums[i-1])
                continue;
            
            int j = i+1, k = n-1;
            
            while(j < k)
            {
                if(nums[i] + nums[j] + nums[k] == 0)
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    while(j < k and nums[j] == nums[j-1])
                        ++j;
                }
                else if(nums[i] + nums[j] + nums[k] < 0)
                    ++j;
                else
                    --k;
            }
        }
        
        return ans;
    }
};
